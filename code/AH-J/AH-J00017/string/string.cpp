#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 2e5+5;
ll n,a[M],b[M];
char c[M];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ///int t0=clock();

    cin >> n;
    ll l=0;
    for(int i=1 ; i<=n ; i++)
    {
        cin >> a[i] >> c[i];
        l+=a[i];
        b[i] = l-a[i];
    }
    ll ans=0;
    ll wzl=1,wzr=l,inl=1,inr=n;
    while(wzl<=l/2 && wzr>=l/2)
    {
        ll le=abs(b[inl+1]-wzl)+1;
        ll ri=abs(wzr-b[inr]);
        if(le>ri)
        {
            if(c[inl]!=c[inr]) ans += ri;
            wzr -= ri;
            inr--;
            wzl += ri;
        }
        else if(le<ri)
        {
            if(c[inl]!=c[inr]) ans += le;
            wzl += le;
            inl++;
            wzr -= le;
        }
        else
        {
            if(c[inl]!=c[inr]) ans += le;
            wzl += le;
            inl++;
            wzr -= ri;
            inr--;
        }
    }
    cout << ans;

    ///cout << "\ntimeuse:" << clock()-t0 << "ms";
    cout << endl;
    return 0;
}
