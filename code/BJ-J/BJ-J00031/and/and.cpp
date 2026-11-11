#include<bits/stdc++.h>
using namespace std;
int n,m,maxn,max_;
int a[200005];
int main(){
    freopen("and.in","w",stdin);
    freopen("and.out","r",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(a[i],maxn);
    }
    if(m==1){
        cout<<maxn;
    }else if(m==n){
        int sumn=a[1];
        for(int i=2;i<=n;i++){
            sumn&=a[i];
        }
        cout<<sumn;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                max_=max(max_,a[i]&a[j]);
            }
        }
        cout<<max_;
    }else{
        sort(a+1,a+n+1);
        int sum=a[n];
        for(int i=n-1;i>=n-m+1;i--){
            sum&=a[i];
        }
        cout<<sum;
    }
    return 0;
}
