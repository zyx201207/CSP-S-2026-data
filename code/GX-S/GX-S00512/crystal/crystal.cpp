#include<bits/stdc++.h>
using namespace std;
long long n , m , mi;
int a[500001],ans[1001];
int main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    mi=m;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    for(int j = 0 ; j<n;j++){
        for(int i = j ; i<n;i++){
            if(mi==0) break;
            for(a[i];a[i]<=a[i+1];a[i]++){
                mi-=1;
            }
            ans[j]++;
        }
    }
    for(int i = 0 ; i<n;i++){
        ans[1] = max(ans[0] , ans[i]);
    }
    cout<<ans[0]+1;
    return 0;
}
