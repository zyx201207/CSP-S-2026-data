#include<bits/stdc++.h>
using namespace std;
long long a[200010],b[10000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    b[0]=1;
    for(int i=1;i<=30;i++){
        b[i]=b[i-1]*2;
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=30;j++){
            if(b[j]==a[i]){
                a[i]=0;
            }
        }
    }
    sort(a+1,a+n+1);
    cout<<a[n-m+1];
    return 0;
}
