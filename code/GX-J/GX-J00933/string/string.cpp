#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],t=1,w,ans;
char c[200001];
string s;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
w=n;
for(int i=1;i<=n;i++)
{
    cin>>a[i]>>c[i];
}
int l=1;
for(int i=2;i<=n;i++)
{
    if(c[i]!=c[i-1])l=0;
}
if(l==1)
{
    cout<<0;
    return 0;
}
while(t<w)
{
    if(c[t]==c[w])
    {
        if(a[t]>a[w])
        {
            a[t]-=a[w];
            w--;
        }
        else if(a[t]==a[w])
        {
            t++;
            w--;
        }
        else if(a[t]<a[w])
        {
            a[w]-=a[t];
            t++;
        }
    }
    else
    {
        if(a[t]>a[w])
        {
            a[t]-=a[w];
            ans+=a[w];
            w--;
        }
        else if(a[t]==a[w])
        {
            ans+=a[w];
            t++;
            w--;
        }
        else if(a[t]<a[w])
        {
            a[w]-=a[t];
            ans+=a[t];
            t++;
        }
    }
}
cout<<ans;
return 0;
}
