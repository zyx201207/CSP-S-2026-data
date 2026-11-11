#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],c[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,ma=0,k=1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<32;){
            if(a[j]/2>1){
                i++;
            }
            if(a[j]%2==0){
                b[j]++;
            }
        }
    }
    for(int z=0;z<m;z++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(b[j]>ma){
                    ma=b[j];
                }
            }
            if(b[i]==ma){
                c[i]=b[i];
                b[i]=-1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(c[i]!=0){
            k=k&a[i];
        }
    }
    cout<<int(k);
    return 0;
}
