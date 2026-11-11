#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[10001];
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int b = m,cnt = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            b -= 1;
            a[j] += 1;
            if(a[j] == a[i+1]){
                if(cnt < i-1) cnt++;
            }
        }
    }
    cout << cnt;
}
