#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans,l;
string s;
//guanzhu bilibili dahongdou009
//guanzhu luogu 884813
struct node{
    ll s;char c;
}a[200005];
//☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭
//❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].s>>a[i].c;
        for(int j=1;j<=a[i].s;j++){s+=a[i].c;l++;}
    }
    if(n<=1){cout<<0;return 0;}
    if(n==2){cout<<min(a[1].s,a[2].s);return 0;}
    for(int i=0;i<l;i++)
    {
        int j=l-i;
        //if(i==j)break;
        if(s[i]!=s[j]){s[i]=s[j],ans++;}
        else s[i]=s[j];
    }
    cout<<ans;
    return 0;
}
