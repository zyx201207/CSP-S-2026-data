#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[10010];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int m=a[1];
        for(int i=2;i<=n;i++){
            m=max(m,a[i]);
        }
        cout<<m;
    }
    if(m==n&&m!=1){
        m=a[1];
        for(int i=2;i<=n;i++){
            m=m&a[i];
        }
        cout<<m;
    }
    if(m==2&&m!=n){
        int m;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                m=max(m,a[i]&a[j]);
            }
        }
        cout<<m;
    }
    return 0;
}
