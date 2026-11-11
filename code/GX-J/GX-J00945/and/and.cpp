#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m,a[N],ans,s[N];
vector<int> v;
void dfs(int ind,int flag,int pos){
    if(flag)
    {
        v[ind]=1;
    }
    else v[ind]=0;
    if(pos>m) return;
    if(ind==n && pos==m)
    {
        int res;
        bool t=0;
        for(int i=1; i<v.size(); i++)
        {
            if(v[i]==1 && t)
            {
                res&=a[i];
            }
            if(v[i]==1 && !t)
            {
                res=a[i];
                t=1;
            }
        }
        ans=max(ans,res);
        return;
    }
    if(ind>=n)
    {
        return;
    }
    dfs(ind+1,0,pos);
    dfs(ind+1,1,pos+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        for(int i=1; i<=n; i++)
        {
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }
    else if(n==m)
    {
        ans=a[1];
        for(int i=2; i<=n; i++)
        {
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==2)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<i; j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
//    else if(m==n-1)
//    {
//      s[1]=a[1];
//        for(int i=2; i<=n; i++)
//        {
//            s[i]=s[i-1]&a[i];
//        }
//        for(int i=1; i<=n; i++)
//        {
//            int res=(s)
//        }
//    }
    else
    {
        v.resize(n+1,0);
        dfs(1,0,0);
        dfs(1,1,1);
        cout<<ans;
    }
    return 0;
}
