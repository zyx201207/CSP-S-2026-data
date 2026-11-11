#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N];
char c[N];
long long l,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i],l+=a[i];
    int L=1,R=n;
    long long Llst=a[1],Rlst=a[n];
    while(1)
    {
        if(L>=R) break;
        if(Llst==Rlst)
        {
            if(c[L]!=c[R]) ans+=Llst;
            Llst=a[++L],Rlst=a[--R];
        }
        else if(Llst<Rlst)
        {
            if(c[L]!=c[R]) ans+=Llst;
            Rlst-=Llst,Llst=a[++L];
        }
        else
        {
            if(c[L]!=c[R]) ans+=Rlst;
            Llst-=Rlst,Rlst=a[--R];
        }
    }
    cout<<ans;
}
