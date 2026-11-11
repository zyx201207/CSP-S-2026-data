#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long x=a[0];
    long long y=a[n-1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(a[j]>a[m-1]){
                x=a[j];
            }else{
                y=a[j];
            }
        }
    }
    cout<<y;
    return 0;
}
