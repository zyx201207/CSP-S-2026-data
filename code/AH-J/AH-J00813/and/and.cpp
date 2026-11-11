#include<bits/stdc++.h>
using namespace std;
int n,m,t[35],t2[35],c,v,u,ans[35],anss;
string s[35][200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        string s0="";
        int cnt=0;
        while(c!=0)s0=char(c%2+'0')+s0,cnt++,c/=2;
        t[cnt]++,t2[cnt]++,s[cnt][t[cnt]]=s0,v=max(v,cnt);
    }
    for(int i=v;i>=1;i--)
    {
        if(t2[i]>=m)
        {
            u=i;
            break;
        }
        for(int j=i+1;j<=v;j++)for(int k=1;k<=t[j];k++)if(s[j][k][j-i]=='1')t2[i]++;
        if(t2[i]>=m)
        {
            u=i;
            break;
        }
    }
    int cnt=0;
    for(int i=u;i>=1;i--)
    {
        int cntt=0;
        for(int j=u;j<=v;j++)for(int k=1;k<=t[j];k++)if(s[j][k][j-i]=='1')
        {
            cntt++;
            for(int p=j-i;p<s[j][k].length();p++)if(s[j][k][p]=='0')ans[p+1]=2;
        }
        cnt++;
        if(cntt>=m&&ans[cnt]==0)ans[cnt]=1;
        else ans[cnt]=2;
    }
    for(int i=1;i<=u;i++)if(ans[i]==2)ans[i]=0;
    for(int i=1;i<=u;i++)anss=anss*2+ans[i];
    cout<<anss;
    return 0;
}
