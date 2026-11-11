#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N],and_[N],ma=INT_MIN;
bool A=true,B=true;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
        if(log2( a[i]+1 )!=int( log2(a[i]+1) )){
            A=false;
        }
        if(a[i]!=i-1){
            B=false;
        }
        if(i>1){
            and_[i]=and_[i-1]&a[i];
        }
        else{
            and_[i]=a[i];
        }
    }
    if(m==n){
        cout<<and_[n];
    }
    else if(m==1){
        cout<<ma;
    }
    else if(m==2){
        int ma_=INT_MIN;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ma_=max(ma_, a[i]&a[j] );
            }
        }
        cout<<ma_;
    }
    else if(m==n-1){
        int ma_=INT_MIN;
        for(int i=1;i<=n;i++){
            ma_=max(ma_,and_[n] & ( a[i] | (~a[i]) ) );
        }
        cout<<ma_;
    }
    else if(A==true){
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        int ans=a[1];
        for(int i=2;i<=m;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else if(B==true){
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        int ans=a[1];
        for(int i=2;i<=m;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else{
        sort(a+1,a+n+1);
        int max_;
        do{
            max_=INT_MIN;
            int t=a[1];
            for(int i=2;i<=m;i++){
                t=t&a[i];
            }
            max_=max(max_,t);
        }
        while(next_permutation(a+1,a+n+1));
        cout<<max_;
    }
    return 0;
}
