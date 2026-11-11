/*
think for a moment:
normally to simulate all the games we need n^2 time (n games * n actions per game)
If we can just see the game and immediately get the result, that would save a lot of time...
Or if we can directly find the results without simulating
The difference between this game and the regular trains card game is that the last card gets retained, so it can still be used to cancel more times
The last card being kept is the same as the first card being kept
This means that for one card type, everything between the first card and the last card of that type gets taken (unlike the regular trains game)

Idea:
Get an array to record when a number last appears, and precalculate how much each number will take away (if only that number does the taking)
This way, we can precalculate how much each scenario will delet




Wait...
Are there alternative ways to directly calculate how many times each number will be kept?
The last number will be kept for every game.
consider this start: 3 1 2 1 3 2 3 1 2 1
The first number of every game is also guaranteed to be kept, since nothing can wrap around it
So when the other side of the first number comes, it can guarantee to cancel everything between
So between the first and last occurence of the first number is guaranteed to be gone
If the first number only appears once the second number is guaranteed to be retained, and if the second one doesn't have another copy, the next can guarantee, and so forth

After that cropping, there are no copies of the first number, so we can apply the same principle

using this to simulate gives O(nm) time


Hang on... We can pre-simulate from only the last number remaining to every number remaining,
and when we do the cropping above the remaining part is guaranteed to be simulated before....
That's it.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=5e5+5;
const ll MAXM=3e5+5;
ll cards[MAXN];//the original order of the cards
ll last_occ[MAXM];//last occurence of each card in original order of cards
bool res[MAXN];//the retained number in one taking, and then it's the next taking
//in the end, it seems like there's not really much use to this array
ll fn_res[MAXM];
ll pointer[MAXN];//for every non-starting scenario, where does one taking lead to
ll times[MAXN];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
   ll n,m;
    cin>>n>>m;
    memset(last_occ,0,sizeof(last_occ));
    for(ll i=1;i<=n;i++)
    {
        cin>>cards[i];
        last_occ[cards[i]]=i;
    }
    //for each scenario, after we do our first cropping we will record the following scenario in an array, but we will put the results not in the array in
    //at the end, we will sum up everything

    for(ll start=n;start>=1;start--)
    {
        //cout<<"take:"<<start<<"to ";
        if(cards[start]==cards[n])
        {
            res[start]=cards[start];
            //cout<<"End      ";
            //cout<<"numbers++:"<<res[start]<<"\n";
            pointer[start]=n+1;
            //everything else = 0
        }
        else
        {
            //one taking
            res[start]=cards[start];
            pointer[start]=last_occ[cards[start]]+1;
            //cout<<pointer[start]-1<<"  "<<cards[start]<<"   number ++:"<<cards[start]<<flush<<"\n";
        }
    }
    //sum up the answers
    for(ll start=1;start<=n;start++)
    {
        times[start]++;//itself
        //cout<<"occurence times:"<<times[start];
        //cout<<" ";
        if(pointer[start]!=n+1)
        {

            times[pointer[start]]+=times[start];
            //cout<<"points to"<<pointer[start];
        }
        else{
            //it is one take
        }

        //sum up itself's changes
        fn_res[cards[start]]+=times[start];
        //cout<<"current ans:";
        /*for(int i=1;i<=m;i++)
        {

            cout<<fn_res[i]<<" ";
        }
        cout<<"\n";*/
    }
    for(ll i=1;i<=m;i++)
    {

        cout<<fn_res[i]<<" ";
    }
}
