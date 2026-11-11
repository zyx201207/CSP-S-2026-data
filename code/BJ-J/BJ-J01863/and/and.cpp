#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int a[200001][33];
int b[33],d[200001];
bool c[200001];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int t;
        cin>>d[i];
        t=d[i];
        int j=1;
        while(t>0){
            a[i][j]=t%2;
            t/=2;
            j++;
        }
    }
    for(int i=30;i>=1;i--){
        int sum=0;
        for(int j=1;j<=n;j++){
            if(!c[j]){
                sum+=a[j][i];
            }
        }
        if(sum>=m){
            b[i]=1;
            for(int j=1;j<=n;j++){
                if(!a[j][i])c[j]=1;
            }
        }
    }
    int ans=0;
    for(int i=30;i>=1;i--){
        ans+=(b[i]<<(i-1));
    }
    cout<<ans;
}
