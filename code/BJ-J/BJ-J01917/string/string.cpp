#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL t[200001];
char c[200001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    LL n,ans=0;
    cin>>n;
    LL la=0,s=0;
    for(int i=1;i<=n;i++)
    {
        LL ta;
        char ch;
        cin>>ta>>ch;
        if(i==1)
        {
            la++;
            t[la]=ta;
            c[la]=ch;
        }
        else
        {
            if(ch==c[la])
            {
                t[la]+=ta;
            }
            else
            {
                la++;
                t[la]=t[la-1]+ta;
                c[la]=ch;
            }
        }
        s+=ta;
        //cout<<s<<endl;
    }
    if(la==1)
    {
        cout<<0;
        return 0;
    }
    LL l=1,r=s,ml=1,mr=la;
    char cl=c[ml],cr=c[mr];
    while(r>l)
    {
        LL bian=min(r-t[mr-1]+1,t[ml]-l)+1;
        //cout<<r-t[mr]<<' '<<t[ml+1]-1-l<<endl;
        //cout<<l<<' '<<r<<' '<<ml<<' '<<mr<<' '<<cl<<' '<<cr<<' '<<bian<<'\n';
        r-=bian;
        l+=bian;
        if(cl!=cr)
        {
            ans+=bian;
        }
        if(r<t[mr-1]+1)
        {
            mr--;
            cr=c[mr];
        }
        if(l>t[ml])
        {
            ml++;
            cl=c[ml];
        }
        //cout<<l<<' '<<r<<' '<<ml<<' '<<mr<<' '<<cl<<' '<<cr<<' '<<bian<<'\n';
    }
    cout<<ans;
    return 0;
}
