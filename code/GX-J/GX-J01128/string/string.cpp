#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long  n,b=0;
    long long a[1005];
    string s[1005];
    long long sum=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        cin >> s[i];
        b=b+a[i];
    }
    for(int i=1;i<b;i++){
        if(s[i]!=s[i-1]) sum++;
    }
    cout << sum;
    return 0;


}
