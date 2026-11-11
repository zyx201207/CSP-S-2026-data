#include<bits/stdc++.h>
using namespace std;
long long n,a[210000],zl,zr,dl,dr,x,s;
char ch[210000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i]>>ch[i];
    }
    dl=0;
    dr=n+1;
    while(dl<dr)
    {
        if(zl==0)
        {
            dl++;
            zl=a[dl];
        }
        if(zr==0)
        {
            dr--;
            zr=a[dr];
        }
        if(dl>=dr)
        {
            break;
        }
        x=min(zl,zr);
        zl-=x;
        zr-=x;
        if(ch[dl]!=ch[dr])
        {
            s+=x;
        }
    }
    cout<<s<<"\n";
    return 0;
}
