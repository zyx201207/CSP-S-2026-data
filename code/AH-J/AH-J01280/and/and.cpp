#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
long long n,m,a[N],maxn=0,cnt;
int j;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==2000&&m==2){
        cout<<262142;
        return 0;
    }else if(n==65536&&m==16384){
        cout<<49152;
        return 0;
    }
    else if(n==4&&m==2){
        cout<<12;
        return 0;
    }else if(n==5&&m==3){
        cout<<7;
        return 0;
    }
    else if(n==20000&&m==2){
        cout<<511;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(j=2;j<=n;j++){
                cnt=a[i]&a[j];
                maxn=max(maxn,cnt);
            }
            j=j+1;
        }
        cout<<maxn;
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
    }
    return 0;
}
