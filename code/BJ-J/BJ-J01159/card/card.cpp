#include<bits/stdc++.h>
using namespace std;
int n,m,s,cnt,a[500009],b[500009],c[500009];
bool f;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int k=1;k<=n;k++){
        s=1;
        for(int i=k;i<=n;i++){
            f=0;
            for(int j=1;j<=s;j++){
                if(b[j]==a[i]){
                    f=1;
                    for(int l=j+1;l<=s;l++){
                        b[l]=0,cnt++;
                    }s-=cnt,cnt=0;
                    b[s]=a[i];s++;
                    break;
                }
            }if(f==0){
                b[s]=a[i];
                s++;
            }
        }for(int i=1;i<s;i++){
            c[b[i]]++;
            b[i]=0;
        }
    }for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }return 0;
}
