//beibao?
/*
another idea:
try for each digit place, and cycle through the numbers
start from the largest digit place, and record the number of ones through it
if it is greater than m (so that digit can be kept), ditch all the numbers without that largest digit as 1
For this, simply bucket sort the numbers as we go through the numbers       or      label the number as inusable for each round (still needs to check which is faster)
otherwise, cycle on
time complexity: O(30n)?
still needs to verify if it is correct
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;
const ll MAXB=35;
ll numbers[MAXN];
bool digits[MAXN][35];
bool flag[MAXN];//if the number is still in; 0 is in, 1 is out   later I can try keeping the vector for the list of numbers, but now I'll use the flagging method
bool fn_num[MAXB];//here it will be stored as individual binary digits, in the end it will be converted
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //cout<<ll(pow(2,31));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {

        cin>>numbers[i];
        for(ll j=31;j>=0;j--)
        {
            ll cv=pow(2,j);
            if(numbers[i]>=cv)
            {
                digits[i][j]=1;
                numbers[i]-=cv;
            }
            //cout<<digits[i][j];
        }
        //cout<<"\n";
    }
    for(ll i=31;i>=0;i--)
    {
        //check if this digit can be kept in    because this is the larger digit, so it is guaranteed to have a dominant influence
        int occ=0;
        for(int j=1;j<=n;j++)
        {
            if(flag[j])continue;
            occ+=digits[j][i];
        }
        //cout<<occ<<" ";
        if(occ>=m)
        {
            //it can be kept
            fn_num[i]=1;
            //everything that will go in the final number will have that digit
            for(int j=1;j<=n;j++)
            {
                if(!digits[j][i])flag[j]=1;//if the digit is 0, then the number will be ditched
            }
        }
        else{
                //it can't be kept
            fn_num[i]=0;
        }
    }
    //cout<<"\n";
    long long ans=0;
    long long eff=pow(2,31);
    for(int i=31;i>=0;i--)
    {
        ans+=eff*fn_num[i];
        //f(fn_num[i])cout<<eff<<" ";
        //cout<<fn_num[i];
        eff/=2;
    }
    //cout<<"ans:";
    cout<<ans;
}
