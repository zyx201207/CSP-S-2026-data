#include<bits/stdc++.h>
using namespace std;
string s;
long long sum,a[200005],b[200005],n,x=1,y=1,xt=0,yt=0,ans;
char an[200005],bn[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>an[i];
    }
    for(int i=n;i>=1;i--)
    {
        b[x]=a[i];
        bn[x]=an[i];
        x++;
    }
    x=1;
    while(1)
    {
        xt++;
        yt++;
        if(an[x]!=bn[y])
        {
            sum++;
        }
        if(xt==a[x])
        {
            xt=0;
            x++;
        }
        if(yt==b[y])
        {
            yt=0;
            y++;
        }
        if(x>n||y>n) break;
    }
    cout<<sum/2;
    return 0;
}

