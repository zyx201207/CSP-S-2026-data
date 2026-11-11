#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,a[100005];
    char c[100005];
    long long ans=0,l=0,mid;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i]>>c[i];
        l+=a[i];
    }
cout << l/2;
}
