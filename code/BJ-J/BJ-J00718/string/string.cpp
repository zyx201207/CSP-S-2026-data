#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n; i++){
        cin >> a[i] >> c[i];
    }
    int cl = 1,cr = n;
    ll suml = a[1],sumr = a[n];
    ll ans = 0;
    while(cl < cr){
        if(suml < sumr){
            if(c[cl] != c[cr]){
                ans += suml;
            }
            sumr -= suml;
            cl++;
            suml = a[cl];
        }else if(suml > sumr){
            if(c[cl] != c[cr]){
                ans += sumr;
            }
            suml -= sumr;
            cr--;
            sumr = a[cr];
        }else{
            //suml == sumr
            if(c[cl] != c[cr]){
                ans += suml;
            }
            cl++,cr--;
            suml = a[cl];
            sumr = a[cr];
        }
    }
    cout << ans;
    return 0;
}
