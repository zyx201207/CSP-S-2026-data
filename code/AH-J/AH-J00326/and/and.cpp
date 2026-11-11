#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int ans,n,m,a[200005],f[200005];
int cf=0b1111111111111111111111111111111;
bool A=1,B=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2){
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }else if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
    }else if(m==n){
        for(int i=2;i<=n;i++){
            a[i]=a[i]&a[i-1];
        }
        ans=a[n];
    }else if(m==n-1){
        for(int i=1;i<=n;i++){
                memset(f,0,sizeof(f));
                f[1]=a[1];
            for(int j=2;j<=n;j++){
                if(i!=j){
                    f[j]=a[j]&f[j-1];
                }else{
                    f[j]=f[j-1];
                }
            }
            ans=max(ans,f[n]);
        }

    }else{
        sort(a+1,a+n+1);
        ans=a[m];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
