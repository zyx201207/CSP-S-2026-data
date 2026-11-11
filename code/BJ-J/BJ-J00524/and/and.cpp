#include<bits/stdc++.h>
using namespace std;
long long a[200005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long maxn=-1e5;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(a[i],maxn);
    }
    long long ans=a[1];
    for(int i=i;i<=n;i++){
        ans=ans&a[i];
    }
    if(n<=20){
        for(int i=1;i<=n;i++){

        }
    }
    if(m==1){
        cout<<maxn;
    }else if(m==2){
        long long num=a[1]&a[2];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                num=max(num,(a[i]&a[j]));
            }
        }
        cout<<num;
    }
    else if(m==n){
        cout<<ans;
    }
    else{
        long long num=a[1];
        for(int i=1;i<=m;i++){
            num=num&a[i];
        }
        cout<<num;
    }
    return 0;
}
