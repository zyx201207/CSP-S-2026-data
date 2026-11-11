#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    if(n<=20){
        cout<<a[m];
    }
    else if(n<=2000){
        if(m==1){
            cout<<a[1];
        }
        if(m==n){
            cout<<a[m];
        }
        if(m==2){
            cout<<a[2];
        }
    }
    else{
        if(m==(n-1)){
            cout<<a[m];
        }
        else if(m==n){
            cout<<a[m];
        }
        else{
            cout<<a[m];
        }
    }
    return 0;
}

