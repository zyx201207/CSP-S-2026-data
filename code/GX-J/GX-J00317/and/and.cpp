#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a[100005];
    int n,m,maxe=0,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            a[i]=a[i]&a[i+j];
        }
        cnt=max(maxe,a[i]);
        maxe=a[i];
        a[i]++;
    }
    cout<<cnt;
    return 0;
}
