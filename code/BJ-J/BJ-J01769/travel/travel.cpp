#include<bits/stdc++.h>
using namespace std;
int k;
struct n{
    long long len;
    char a;
} S[200005];
n S2[200005];
int main(){
    freopen("string.in", "r",stdin);
    freopen("string.out", "w",stdout);

    cin >> k;
    long long s = 0;
    for (long long i = 1; i <= k; i++){
        cin >> S[i].len >> S[i].a;
        S2[k - i + 1].len = S[i].len;
        S2[k - i + 1].a = S[i].a;
        s += S[i].len;
    }
    long long sum = 0;
    long long i1 = 0, i2 = 0;
    long long p1 = 0;
    long long p2 = 0;
    //<<s<<endl;
    while (p1 < s || p2 < s){
        long long t = abs(p1 - p2);

        if (p1 == p2){
            i1 ++;
            p1 += S[i1].len;
        }
        else if (p1 > p2){
            i2 ++;
            p2 += S2[i2].len;
            if (S[i2].a != S2[i1].a){
                if (p1 > p2) sum += S2[i2].len;
                else sum += S2[i2].len -(p2-p1);
            }
        }
        else if(p1 < p2){
            i1 ++;
            p1 += S[i1].len;
            if (S[i2].a != S2[i1].a){
                if (p1 < p2) sum += S[i1].len;
                else sum += S[i1].len -(p1-p2);
            }
        }
        //cout<<t<<' '<<p1<<' '<<p2<<' '<<sum<<endl;
    }
    cout << min(s - sum/2,sum / 2);
    return 0;
}
