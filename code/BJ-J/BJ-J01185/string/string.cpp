#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

ll n,len;
vector<ll> v,sum;
vector<char> ch;
ll ans = 0;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;
    v.resize(n);
    sum.resize(n);
    ch.resize(n+1);

    for(int i=0;i<n;i++){
        cin >> v[i] >> ch[i];
    }
    sum[0] = v[0];
    for(int i=1;i<n;i++){
        sum[i] = sum[i-1] + v[i];
    }

    //for(int i=0;i<n;i++){
    //    cout << sum[i] << ' ';
    //}
    //cout << endl;

    len = sum.back();

    ll lst = 0;
    for(int i=0;lst<len/2;i++){

        ll rl = len - sum[i];
        ll rr = len - lst;
        if(rl<len/2){
            rl = len/2;
            if(rr<=rl){
                break;
            }
        }



        int posl = upper_bound(sum.begin(), sum.end(), rl) - sum.begin();
        int posr = upper_bound(sum.begin(), sum.end(), rr) - sum.begin() - 1;

        if(ch[i]!=ch[posl]){
            ans += sum[posl] - rl;
            //cout << ans << endl;
        }
        for(int j=posl+1;j<n&&sum[j]<=sum[posr];j++){
            if(ch[i]!=ch[j]){
                ans += sum[j] - sum[j-1];
                //cout << j << ' ' << ans << endl;
            }
        }

        if(ch[i]!=ch[posr+1]){
            ans += rr - sum[posr];
            //cout << ans << endl;
        }

        //cout << i << ' ' << ans << ' ' << lst << ' ' << sum[i] << endl;
        //cout << rl << ' ' << rr << ' ' << posl << ' ' << posr << endl;

        lst = sum[i];
    }

    cout << ans;

    cout << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
/*
6
1 a
5 b
2 c
2 b
2 a
3 e

abbbbbc c bbaaeee
1 5 2 2  2  3
1 6 8 10 12 15
14 15
9 14

aabbc
2 2 1
2 4 5

*/
