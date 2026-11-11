#include<bits/stdc++.h>
using namespace std;
string a,s;
long long n,i,m,ch=0,b=0,j;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>m; cin>>s;
        for(j=1;j<=m;++j)
            a+=s;
    }
    //cout<<a;
    ch=a.size();
    i=0;
    while(i<ch-i-1)
    {
        if(a[i]!=a[ch-i-1]) ++b;
        i++;
    }
    cout<<b;
    return 0;
}
