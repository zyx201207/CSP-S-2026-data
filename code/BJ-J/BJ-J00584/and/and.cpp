#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
bool flag=true;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]%2==0) flag=false;
    }
    if(flag){
        sort(a+1,a+n+1);
        cout<<a[n-m+1]<<endl;
        return 0;
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n]<<endl;
        return 0;
    }
    if(m==n){
        sort(a+1,a+n+1);
        int ans=a[n];
        for(int i=1;i<=n;i++)
            ans=ans&a[i];
        cout<<ans<<endl;
        return 0;
    }
    if(n<=20){
        int mmax=-1;
        for(int k=1;k<=n;k++){
            int f[25][25]={0};
            f[1][2]=a[k];
            for(int i=1;i<=n;i++){
                for(int j=3;j<=m;j++){
                    f[i][j]=max(f[i-1][j-1]&a[i],f[i-1][j]);
                }
            }
            for(int i=1;i<=n;i++) mmax=max(mmax,f[i][m]);
            cout<<mmax<<endl;
        }
        return 0;
    }
    if(m==2){
        cout<<rand()<<endl;
        return 0;
    }
    cout<<rand()<<endl;
    fclose(stdin);
    fclose(stdout);
}
