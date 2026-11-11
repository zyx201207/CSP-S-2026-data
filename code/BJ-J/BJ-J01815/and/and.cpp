#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;
    int m;
    int cnt = 0;
    cin>>n>>m;
    int a[100001];
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    sort(a + 1, a+ n + 1);
    for(int i = m; i >= 1; i++){
        while(a[i] != 0){
            if(cnt % 2 == 1 && a[i] % 2 == 1){
                cnt += 1;
                cnt *= 2;
            }
            else if(cnt % 2 == 0 && a[i] % 2 == 0){
                cnt += 1;
                cnt *= 2;
            }
            a[i] += 1;
            a[i] /= 2;
        }
    }
    cout<<cnt;
}
