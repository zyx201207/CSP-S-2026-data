#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

ll n,m,ans = 0;
vector<ll> v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    v.resize(n);

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());


    ll cnt = 1, now = 0;
    for(int l=0,r=1;l<n;l++){

        for(r=max(l,r);r<n;){



            ll dlt = v[r] - v[r-1];

            if(now + dlt*cnt <= m){
                now += dlt * cnt;
                cnt++;
                r++;
            }else{
                break;
            }

        }

        //cout << l << ' ' << r << ' ' << now << ' ' << cnt << endl;
        ans = max(ans, cnt);

        now -= v[r-1] - v[l];
        cnt--;
    }

    cout << ans;

    cout << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
