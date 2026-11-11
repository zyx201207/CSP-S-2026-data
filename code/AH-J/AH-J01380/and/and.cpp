#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,mi=1e9,t[5];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int maxx=0,zong,f=0,f1=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i-1){
            f1=1;
        }
        if((a[i]+1)&a[i]!=0){
            f=1;
        }
        if(i==1){
            zong=a[1];
        }
        else{
            zong^=a[1];
        }
        maxx=max(maxx,a[i]);
    }
    if(m==1){//5
        cout<<maxx;
        return 0;
    }
    if(m==n){//10
        cout<<zong;
        return 0;
    }
    if(f==0){//15
        sort(a+1,a+1+n);
        cout<<a[n-m+1];
        return 0;
    }
    if(m==2){
        maxx=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,a[i]^a[j]);
            }
        }
        cout<<maxx;
        return 0;
    }//30
    if(f1==0){
        int ans=a[n];
        for(int i=n;i>=n-m+1;i--){
            ans^=a[i];
        }
        cout<<ans;
        return 0;
    }//40
    if(maxx<=4){
        for(int i=1;i<=n;i++){
            t[a[i]]++;
        }
        if(t[4]>=m){
            cout<<4;
            return 0;
        }
        if(t[4]+t[3]+t[1]>=m){
            cout<<3;
            return 0;
        }
        if(t[4]+t[3]+t[1]+t[2]>=m){
            cout<<2;
            return 0;
        }
        cout<<0;
        return 0;
    }//50
    return 0;
}
