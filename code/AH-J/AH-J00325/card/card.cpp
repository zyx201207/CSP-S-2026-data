#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],b[1000005],t[10000005],cnt=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=cnt;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==a[j]){
                for(int k=i+1;k<=j;k++){
                    b[k]=0;
                }
            }else{
                b[i]=a[i];
            }
        }
        for(int i=1;i<=n;i++){
            t[b[i]]++;
        }
        for(int i=1;i<=n;i++){
            b[i]=0;
        }
        cnt++;
    }

    for(int i=1;i<=300000;i++){
        if(t[i]>0){
            cout<<t[i]<<" ";
        }
    }
    return 0;
}

