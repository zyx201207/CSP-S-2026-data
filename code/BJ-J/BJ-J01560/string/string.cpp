#include<bits/stdc++.h>
using namespace std;
int n;
long long shuliang[200005];
char zifu[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>shuliang[i]>>zifu[i];
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    long long cnt=0;
    for(int l=1,r=n;l!=r;)
    {
        if(shuliang[l]<=shuliang[r])
        {
            if(zifu[l]!=zifu[r])
            {
                cnt+=shuliang[l];
            }
            shuliang[r]-=shuliang[l];
            l++;

        }
        else if(shuliang[l]>shuliang[r])
        {
            if(zifu[l]!=zifu[r])
            {
                cnt+=shuliang[r];
            }
            shuliang[l]-=shuliang[r];
            r--;
        }
    }
    cout<<cnt;
    return 0;
}
