#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int n,m;
int finding1(){
    int maxx=a[0];
    for(int i=0;i<n;i++){
        maxx=max(a[i],a[0]);
    }
    return maxx;
}
int finding2(){
    int maxx=a[0]&a[1];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            maxx=max(maxx,a[i]&a[j]);
        }
    }
    return maxx;

}
int findingn(){
    int ans=a[0]&a[1];
    if(n>=2){
        for(int i=2;i<n;i++){
            ans=ans&a[i];
        }
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and1.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<finding1();
    }
    if(m==2){
        cout<<finding2();
    }
    if(m==n){
        cout<<findingn();
    }
    return 0;
}
