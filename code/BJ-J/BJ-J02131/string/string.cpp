#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 2e5 + 5;

ll a[N];
ll sum,mid;
char c[N];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin >> n;
    string s = "";
    s+='1';
    for(int i = 1;i<=n;i++){
        cin >> a[i] >> c[i];
        for(int j = 1;j<=a[i];j++){
            s+=c[i];
        }
        sum+=a[i];
    }
    if(sum % 2 == 0){
        mid = sum/2;
    }else{
        mid = (sum+1)/2;
    }
    ll ans = 0;
    if(sum % 2 == 0){
        for(int i = 1;i<=mid;i++){
            if(s[i]!=s[sum-i+1]){
                ans++;
            }
        }
    }else{
        for(int i = 1;i<mid;i++){
            if(s[i]!=s[sum-i+1]){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
