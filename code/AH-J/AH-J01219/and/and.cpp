#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    int a[400000]={0};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int b=0;
        for(int i=1;i<=n;i++){
            if(a[i]>b){
                b=a[i];
            }
        }
        cout<<b;
    }
    if(m==2){
        int x=0,z;
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                z=a[i]&a[j];
                if(z>x){
                    x=z;
                }
            }
        }
        cout<<x;
    }
    return 0;
}

