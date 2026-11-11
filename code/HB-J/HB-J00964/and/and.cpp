#include<bits/stdc++.h>
using namespace std;
int a[200005],v[200005],p[200005],ans=0,m,n;
void aaa(int k,int ss)
{
    if(k==m+1)
    {
        int S=0;
        for(int i=1;i<=m;i++)
        {
            if(i==1)
                S=p[i];
            else
                S=S&p[i];
        }
        ans=max(ans,S);
    }
    for(int i=ss;i<n;i++)
    {
        if(v[i]==0)
        {
            v[i]=1;
            p[k]=a[i];
            aaa(k+1,i);
            v[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    aaa(1,0);
    cout<<ans;
    return 0;
}
