#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==n){
       int p=a[1]; 
       for(int i=2;i<=n;i++){
            p&=a[i];  
       }
       cout<<p;
       return 0;   
    }
    sort(a+1,a+n+1,greater<int>());
    if(m==1){
        cout<<a[1];
        return 0;
    }
    if(m==2){
       int p=a[1]&a[2];
       for(int i=2;i<=n;i++){
           if(a[i-1]==a[i]){
              cout<<max(p,a[i-1]);
              return 0;
           }
       }
    }
    return 0;
}
