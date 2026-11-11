#include<bits/stdc++.h>
using namespace std;

long long a[10000000005];
char c[1000000005];
long long s[100000000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        for(int j=1;j<=a[i];j++){
            s[j]=c[i];
        }
    }
    int cnt=0;
    for(int i=1;i<=n/2;i++){
        for(int j=n;j>n/2;j--){
            if(s[i]!=s[j]){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
