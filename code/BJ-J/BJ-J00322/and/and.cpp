#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int cmpr(int a,int b){
    int a2=a;
    int cnt=0;
    while(a2){
        if(a2%2)cnt++;
        a2=a2>>1;
    }
    a2=cnt;
    int b2=b;
    cnt=0;
    while(b2){
        if(b2%2)cnt++;
        b2=b2>>1;
    }
    b2=cnt;
    bool ans;
    if(a2==b2){
        ans=(a>=b);
    }
    else{
        ans=(a2>=b2);
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1){
        int mx=0;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            if(a>mx)mx=a;
        }cout<<mx;
    }else if(m==n){
        int a,ans=INT_MAX;
        for(int i=0;i<n;i++){
            cin>>a;
            ans=ans&a;
        }
        cout<<ans;
    }else{
        int a[200005];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,(int*)a+n,cmpr);//more-less
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    return 0;
}
