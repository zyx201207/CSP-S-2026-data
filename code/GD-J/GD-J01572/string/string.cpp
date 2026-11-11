#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5+10;
struct nd{
    ll s;
    char zf;
}cn[N];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ll n,ans=0,m=0,sn=0;
    cin >> n;
    ll id=n,id2=1;
    for (ll i = 1; i <= n;i++){
        cin >> cn[i].s >> cn[i].zf;
        m+=cn[i].s;
    }
	while(id>0&&id2<=n){
        ll s1 = cn[id].s;
        while(s1){
            if(cn[id].zf==cn[id2].zf){
                if(s1>=cn[id2].s){
                    s1 -= cn[id2].s;
                    cn[id2].s=0;
                    id2++;
                }else{
                    cn[id2].s-=s1;
                    s1 = 0;
                }
            }else {
                if (s1 >= cn[id2].s){
                    s1 -= cn[id2].s;
                    ans += cn[id2].s;
                    cn[id2].s=0;
                    id2++;
                }
                else{
                    ans += s1;
                    cn[id2].s-=s1;
                    s1 = 0;
                }
            }
        }id--;
    }cout <<ans;

    return 0;
}
