#include <bits/stdc++.h>
using namespace std;
int a[200001];
int sum_f[200001];
int sum_b[200001];
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int maxx = 0;
    cin>>n>>m;
    for(int f = 1; f<=n; f++){
        cin>>a[f];
        maxx = max(maxx,a[f]);
        sum_f[f] = sum_f[f-1]&a[f];
    }
    for(int f = n; f>=1; f--){
        sum_b[f] = sum_b[f-1]&a[f];
    }
    if(m == 1){
        cout<<maxx;
        return 0;
    }
    if(m == n-1){
        int ans = 0;
        for(int f = 1; f<=n; f++){
            ans = max(ans,sum_f[f-1]&sum_b[f+1]);
        }
        cout<<ans;
        return 0;
    }
    if(m == n){
        cout<<sum_f[n];
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    for(int f = 1; f<n; f++){
        if(a[f] == a[f+1]){
            cout<<a[f];
            return 0;
        }
    }
    return 0;
}
