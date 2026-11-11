#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n;
ll a[N];char c[N];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ll idx=0,j=1;
    char s[N];
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(j=1;j<=a[i];j++)
        {
            s[j+idx]=c[i];
        }
        idx+=(j-1);
        //cout<<"idx+="<<j<<" new_idx:"<<idx<<"\n";
    }

    //cout<<"idx"<<idx<<"\n";
    //for(ll i=1;i<=idx;i++) cout<<s[i];
    //cout<<"\n";

    ll cnt=0;
    for(ll i=1;2*i<=idx;i++)
    {
        if(s[i]!=s[idx-i+1])
        {
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
//LuoTianYi NB!
//by Luogu@HuangRuibo uid:1286421  QwQ
//by BiliBili@HuangRuibo <-关注喵！
//555 CSP-J都好难喵 我是蒟蒻喵
//rp++;
