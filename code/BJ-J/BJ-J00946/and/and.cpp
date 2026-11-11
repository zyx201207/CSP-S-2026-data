#include<bits/stdc++.h>
using namespace std;
int n,m,s,a[1000000],dp[1000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i = n;i >= 1;i--){
        for(int j = 1;j < i;j++){
            if(a[j]<a[j+1]){
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    s = a[1];
    for(int i = 2;i <= m;i++){
        s = s&a[i];
    }
    cout<<s;
    return 0;
}