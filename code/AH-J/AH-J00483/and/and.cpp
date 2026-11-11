#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[200001],y[200001],maxy[10000000001]={0};
int qy(int a){
    int ys;
    for(int i=1;i<=30;i++){
        if(pow(2,i)>=a){
            ys=a-pow(2,i-1);
            break;
        }
    }
    return
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    sort(a,a+n,cmp);
    if(m==n){
        ans=a[0];
        for(int i=1;i<n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        cout<<a[0];
        return 0;
    }
    if(qy(n)==0){
        for(int i=0;i<m;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    else{
        cout<<a[m-1];
        return 0;
    }
}
