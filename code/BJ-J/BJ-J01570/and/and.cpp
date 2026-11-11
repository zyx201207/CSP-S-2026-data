#include<bits/stdc++.h>
using namespace std;
//int dp[200005][35];
vector<bitset<32> > a;
bool b[200005];
long long ans=0,ansm=0;;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
int n,m;
cin>>n>>m;
//cout<<n<<m;
for(int i=1;i<=n;i++)
{int t;
    cin>>t;
    bitset<32> tt=t;
    a.push_back(tt);
}
for(int i=30;i>=0;i--)
{
    //cout<<1;
    int cnt=0;
    for(int j=1;j<=n;j++)
    {
        if(b[j])
        {
            b[j]=(a[j].to_ulong()&((int)pow(2,i)));
    cnt+=b[j];
        }

    }
    if(cnt>=m)
    {
        ans+=pow(2,i);
    }
    else{

            ansm=max(ans,ansm);
            ans=0;
        memset(b,1,sizeof(b));
    }

}
cout<<ansm<<endl;
}
