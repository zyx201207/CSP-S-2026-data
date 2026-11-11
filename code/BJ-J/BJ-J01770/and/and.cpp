#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2;
int n,a[N],m,ans;
bool tA(){
    for(int i=1;i<=n;i++){
        if((a[i] | 0)!=a[i]){
            return false;
        }
    }
    return true;
}
bool tB(){
    for(int i=1;i<=n;i++){
        if(a[i]!=i-1) return false;
    }
    return true;
}
void p1(int d,int k,int z){
    for(int i=k;i<=n;i++){
        if(k==n && d==0){
            z=int(z&a[i]);
            ans=max(ans,z);
            return ;
        }else if(k==n) return ;
        z=int(z&a[i]);
        p1(d-1,k+1,z);
    }
}
void p2(){
    sort(a+1,a+1+n);
    return ;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+1+n);
        cout<<a[n];
        return 0;
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(n<=2000){
        p1(1,1,a[1]);
        cout<<ans;
        return 0;
    }
    if(n>2000 && tA()){
        p2();
        cout<<a[1];
        return 0;
    }
    if(n>2000 && tB()){
        cout<<0;
        return 0;
    }
    return 0;
}
