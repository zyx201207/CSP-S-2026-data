#include<bits/stdc++.h>
using namespace std;
long long m,n,w,a[200020],b1[19999999],b2[19999999];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    w=n;
    for(int i=1;i<+n;i++){
        b1[i]=a[i];
    }
    for(int i=1;i<=m-1;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=w-1;k++){
                if(i%2==0){
                    b2[j]=b1[k]&b1[k+1];
                }else{
                    b1[j]=b2[k]&b2[k+1];
                }
            }
            w=w-1;
        }
    }
    if(m%2==0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i+1;j++){
                max(b2[j],b2[j+1]);
            }
        }
        cout<<b2[1];
    }else{
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i+1;j++){
                max(b1[j],b1[j+1]);
            }
        }
        cout<<b1[1];
    }
    return 0;
}
