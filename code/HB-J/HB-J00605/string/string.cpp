#include<bits/stdc++.h>
using namespace std;

int a[200005];
char c[200005];

int main(){
    freopen("string.in",stdin);
    freopen("string.out",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i]
    }
    int flag=0;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=1;j--){
            if(a[i]==a[j] && c[i]==c[j]) flag=1;
            else flag=0;
        }
    }
    if(flag) cout << 0;
    else{
        flag=1;
        for(int i=1;i<=n-1;i++){
            if(c[i]!=c[i+1]) {
                flag=0;
                break;
            }
        }
        if(flag) cout << 0;
    }
    return 0;
}

