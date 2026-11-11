#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int m=a[1];
        for(int i=2;i<=n;i++){
            if(a[i]>m) m=a[i];
        }
        cout<<m;
    }
    else if(m==n){
        int sum=-1;
        for(int i=1;i<=n;i++){
            sum&=a[i];
        }
        cout<<sum;
    }
    return 0;
}
