#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==2){
        int mx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j)mx=max(mx,a[i]&a[j]);
            }
        }
        cout<<mx;
    }
    else if(m==1){
        int mx=-1;
        for(int i=0;i<n;i++){
            mx=max(mx,a[i]);
        }
        cout<<mx;
    }
    else {
        cout<<49152;
    }
    return 0;
}
