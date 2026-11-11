#include<bits/stdc++.h>
using namespace std;
long long qz[500009];
long long n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    qz[0]=0;
    int u=0;
    for(int i=1;i<=n;i++){
        cin>>qz[i];
        if(qz[i]!=i){
            u=1;
        }
    }
    if(u==0){
        int ans=0;
        int r=1;
        for(int i=1;i<=n;i++){
            if(m>=r){
                m-=r;
                r++;
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    sort(qz+1,qz+n+1);
    for(int i=n;i>=1;i--){
        qz[i]=qz[i]-qz[i-1];
    }
    int s=0;
    for(int i=2;i<n;i++){
        if(qz[i]!=qz[i+1]){
            s=1;
            break;
        }
    }
    if(s==0){
        int ans2=0;
        int cha0=qz[2];
        int cha=qz[2];
        for(int i=1;i<=n;i++){
            if(m>=cha){
                ans2++;
                m-=cha;
                cha+=cha0;
            }
        }
        cout<<ans2;
        return 0;
    }
    int maxl=1;
    for(int i=1;i<=n-maxl+1;i++){//start point
        for(int j=maxl;j<=n-i+1;j++){//length
            int h=0;//point
            int maxn=0;//steps
            for(int k=i;k<=j+i-1;k++){
                maxn+=qz[k]*h;
                h++;
            }
            if(maxn<=m){
                maxl=j;
            }else{
                break;
            }
        }
    }
    cout<<maxl;
    return 0;
}
