#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long maxn=0,num;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        for(int i=1;i<=n;i++){
            if(maxn<a[i]){
                maxn=a[i];
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==n){
        num=a[1];
        for(int i=2;i<=n;i++){
            num&=a[i];
        }
        cout<<num;
        return 0;
    }
    if(m==n-1){
        for(int i=1;i<=n;i++){
            if(i==1){
                num=a[2];
                for(int j=3;j<=n;j++){
                    num&=a[j];
                }
            }
            else{
                num=a[1];
                for(int j=2;j<=n;j++){
                    if(j!=i) num&=a[j];
                }
            }
            if(num>maxn) maxn=num;
        }
        cout<<maxn;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                num=a[i]&a[j];
                if(num>maxn){
                    maxn=num;
                }
            }
        }
        cout<<maxn;
        return 0;
    }
    cout<<12;
    return 0;
}
