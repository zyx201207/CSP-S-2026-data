#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++ ){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    long long ans = 0;
    for(int i = 1; i <= m; i++ ){
        if(i == 1){
            ans = a[i];
        }else{
            ans &= a[i];
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
