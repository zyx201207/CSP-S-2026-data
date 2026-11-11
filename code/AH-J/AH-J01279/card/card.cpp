#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000100];
int cnt=0;
int card(int a){
    for(int i=0;i<a;i++){
        if(a>=cnt){
            cnt-=a;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1){
            cout<<a[i]+a[i+1]<<" ";
            cnt+=a[i];
            for(int k=0;k<m;k++){
                if(a[i]>=a[i-1]){
                    cout<<cnt*3+1<<" ";
                }
            }
        }else if(a[i]==a[i-1]){
            for(int j=0;j<m;j++){
                if(card>=0){
                    cnt+=a[i-1]+a[i];
                }
                cout<<cnt<<" ";
                cnt+=a[i];
            }
        }
    }
    return 0;
}
