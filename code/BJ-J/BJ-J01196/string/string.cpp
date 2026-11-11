#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
ll a[N],n,ans;
char c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i] >> c[i];
    ll l = 1,r = n,ls = a[1],rs = a[n];
    while(l < r){
        //printf("%d %d %d %d %d\n",l,r,ls,rs,ans);
        if(ls != rs){
            if(ls > rs){
                if(c[l] != c[r]) ans += rs;
                ls -= rs;
                rs = 0;
            }
            else{
                if(c[l] != c[r]) ans += ls;
                rs -= ls;
                ls = 0;
            }
        }
        else{
            if(c[l] != c[r]) ans += ls;
            ls = 0;
            rs = 0;
        }
        //printf("#%d %d %d %d %d\n",l,r,ls,rs,ans);
        if(ls == 0){
            l++;
            ls = a[l];
        }
        if(rs == 0){
            r--;
            rs = a[r];
        }
    }
    cout << ans << endl;


    return 0;
}
