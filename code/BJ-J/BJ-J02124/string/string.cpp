#include<bits/stdc++.h>
using namespace std;
long long n,a[200100];
string s,newstr;
char alph[20010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>alph[i];
    for(int i=0;i<n;i++)
        for(int j=1;j<=a[i];j++)
            s[i]=alph[i+1];
    for(int i=n;i>0;i--)
        newstr[i]=s[n-i];
    if(newstr==s)
        cout<<0;
    if(s.size()<=2)
        cout<<1;
    else
        cout<<2;
    return 0;
}
