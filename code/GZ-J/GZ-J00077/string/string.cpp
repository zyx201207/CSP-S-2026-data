//GZ-J00077 中央民族大学附属中学贵阳学校 李思润
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ll n;
    cin>>n;
    vector<char> s;
    ll sum=0;
    while(n--)
    {
        ll a;
        char b;
        cin>>a>>b;
        for(ll j=sum;j<a+sum;j++)s.emplace_back(b);
        sum+=a;
    }
    ll ans=0;
    ll i=0,j=sum-1;
    while(i,j)
    {
        if(i>=j)break;
        if(s[i]!=s[j])ans++;
        i++;
        j--;

    }
    cout<<ans<<endl;
    return 0;
}
