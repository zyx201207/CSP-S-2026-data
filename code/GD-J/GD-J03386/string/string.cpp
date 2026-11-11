#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        long long a;
        string b;
        cin >> a >> b;
        for(long long j=1;j<=a;j++){
            s+=b;
        }
    }
    long long sum =0;
    for(long long i=0;i<n/2;i++){
        if(s[i]!=s[n/2-i]){
            sum++;
        }
    }
    cout << sum;
}
