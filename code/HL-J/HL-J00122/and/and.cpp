#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[1000086];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-i;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    cout<<a[1];
    return 0;
}
