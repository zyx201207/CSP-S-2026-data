/*
Ideas:
1. binary split answers
If we know how many crystals we want to have, we can just calculate how many moves a group of crystals (neighboring) needs to have for it to get to the end crystal's points
the exact way: We would have already calculated the last group. It's members (aside from the first) needs to reach the new crystal in front, and they are all equal
so we can just add the new increase amount from the front crystal
and subtract the number of moves spent on the crystal not in the new crystal group.
This is O(n) per try, so the end result is O(n log n)

*/

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll MAXN=5e5+5;
long long siz[MAXN];//size of each crystal
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    //int size[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>siz[i];
    }
    sort(siz+1,siz+n+1);
    ll lans=1,rans=n;
    while(lans!=rans)
    {
        int att=(lans+rans+1)/2;
        //cout<<"attempt: "<<att<<"\n";
        //try out if m moves can be enough for this many crystals
        ll usage=0,min_usage=ULLONG_MAX;
        //calculate beginning usage
        ll flag=1;//there is some risk of overflow, so this records if the tally was successfully kept/
        //I just realized something: if the tally was not kept, then afterwards it can go wrong when handling with totally legitimate numbers
        //I double-checked, I think it won't overflow

        for(int i=1;i<att;i++)
        {
            /*if(m-usage<(siz[att]-siz[i]))
            {
                flag=0;
                break;
            */
            usage+=(siz[att]-siz[i]);
        }
        if(flag)
        {
            min_usage=min(usage,min_usage);
        }
        //cout<<usage<<"\n";
        for(int i=att+1;i<=n;i++)
        {
            flag=1;
            //the new crystal size will be siz[i]
            usage-=(siz[i-1]-siz[i-att]);
            /*if((m-usage)/(att-1)<(siz[i]-siz[i-1]-1))//should't require -1, this is just for extra leniency
            {
                flag=0;
            }*/
            usage+=(att-1)*(siz[i]-siz[i-1]);
            if(flag)
            {
                min_usage=min(min_usage,usage);
            }
            //cout<<usage<<"\n";
        }
        //cout<<min_usage<<" "<<m<<"\n";
        if(min_usage<=m)
        {
            lans=att;
        }
        else
        {
            rans=att-1;
        }
    }
    cout<<lans;
}
