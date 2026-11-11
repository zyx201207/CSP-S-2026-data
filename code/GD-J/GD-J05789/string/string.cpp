#include<bits/stdc++.h>
using namespace std;
long long n,l = 0,ans = 0;
char arr[100000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a,k;
    char s;
    cin >> n;
    k = n;
    while(k--){
        cin >> a >> s;
        for(int i = 0;i < a;i++){
            arr[l++] = s;
        }
    }
    for(int i = 0;i <= l/2;i++){
        if(arr[i] != arr[l-1-i]){
            arr[l-1-i] = arr[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}

