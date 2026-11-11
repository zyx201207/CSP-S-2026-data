#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    //将字符串s做好初始化
    while(n--)
    {
        ll m;
        char c;
        cin>>m>>c;
        while(m--)
        {
            s+=c;
        }
    }
    for(ll i=0;i<s.size();++i)
    {
        if(s[i]!=s[s.size()-i-1])
        {
            cnt++;
        }
    }
    cout<<cnt/2;
    return 0;
}
