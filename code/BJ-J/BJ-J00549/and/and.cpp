#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==n){
        int l=a[0]&a[1];
        for(int i=2;i<n;i++){
            l=l&a[i];
        }
        cout<<l;
        return 0;
    }
    if(m==1){
        sort(a+0,a+n);
        cout<<a[n-1];
    }
    if(m==2){
        int mx=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(mx<(a[i]&a[j])){
                    mx=a[i]&a[j];
                }
            }
        }
        cout<<mx;
    }
    if(m==3){
        int mx=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(mx<(a[i]&a[j]&a[k])){
                        mx=a[i]&a[j]&a[k];
                    }
                }
            }
        }
        cout<<mx;
    }
    if(m=n-1){
        int mx=-1;
        for(int i=1;i<n;i++){
            int l=a[0];
            for(int j=1;j<n;j++){
                if(j==i){
                    continue;
                }
                l=l&a[j];
            }
            mx=max(mx,l);
        }
        int l=a[1];
        for(int i=2;i<n;i++){
            l=l&a[i];
        }
        cout<<max(mx,l);
    }
    return 0;
}