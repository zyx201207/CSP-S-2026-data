#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long st,ed;
}a[200005];
int n,f=0;
long long s=0,b[200005],ss=0,sss=0,ans=0,la=0;
long long pos;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i]>>c[i];
        a[i].st=s+1;
        a[i].ed=s+b[i];
        s+=b[i];
    }
    if(s%2==0) ss=s/2;
    else ss=s/2+1;
    la=ss;
    for(int i=1;i<=n;i++)
    {
        sss+=b[i];
        if(sss>ss)
        {
            if(f==0)
            {
                pos=i;
                f=1;
            }
            while(1)
            {
                if(a[pos].st<=ss-(sss-ss)&&a[pos].ed>=ss-(sss-ss))
                {
                    if(c[pos]!=c[i]) ans+=sss-la;
                    la=sss;
                    break;
                }
                else
                {
                    if(c[pos]!=c[i]) ans+=ss+ss-a[pos].st-la;
                    la=ss+ss-a[pos].st;
                    if(pos==1) break;
                    pos--;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
