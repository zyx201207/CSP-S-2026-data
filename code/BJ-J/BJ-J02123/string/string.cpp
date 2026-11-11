#include<bits/stdc++.h>
using namespace std;

int n,a[200005];
char c[200005];

char ac(int x){
    int i=1;
    while(x>a[i]){
        x-=a[i];
        i++;
    }
    return c[i];
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int L=0;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        L+=a[i];
    }
    int ans=0;
    for(int i=1;i<=L/2;i++){
        if(ac(i)!=ac(L+1-i)) ans++;
    }
    cout << ans;
    return 0;
}