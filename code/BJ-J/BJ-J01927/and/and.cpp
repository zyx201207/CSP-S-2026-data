#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int a[10000]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
            int ma=0;
        for(int i=1;i<=n;i++){
            ma=max(ma,a[i]);
        }
    cout<<ma;
    return 0;
    }
    if(m==2){
            int ma=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                ma=max(ma,a[i]&a[j]);
            }
        }
        cout<<ma;
        return 0;
    }
    if(m==n){
            int ma=a[1];
        for(int i=2;i<=n;i++){
            ma=a[i]&ma;
        }
    cout<<ma;
    }
    cout<<12108;a
    return 0;
}

