#include <bits/stdc++.h>
using namespace std;
string s;
char b;
long long n,m,l,k,a,x,y,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long w[200000];
    char e[200000];
    for(long long i=0;i<n;i++)
    {
        cin>>a>>b;
        w[i]=a;
        e[i]=b;
    }
    x=0;
    y=n-1;
    for(long long i=0;i<n*2;i++)
    {
        if(w[x]>w[y])
        {
            if(e[x]!=e[y]) ans+=w[y];
            w[x]-=w[y];
            w[y]=0;
            y--;
        }
        else if(w[x]<w[y])
        {
            if(e[x]!=e[y]) ans+=w[x];
            w[y]-=w[x];
            w[x]=0;
            x++;
        }
        else if(w[x]==w[y])
        {
            if(e[x]!=e[y]) ans+=w[x];
            w[x]=0;
            w[y]=0;
            x++;
            y--;
        }
        else if(w[x]==0||w[y]==0) break;
    }
    cout<<ans;
    return 0;
}
