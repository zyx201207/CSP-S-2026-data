#include<bits/stdc++.h>
using namespace std;
int a[200005];//每一个数
int t[50];//从2^0-2^30
bool b[200005][50];//将每一个数拆成二进制后的结果
int c[50];
bool d[50];//操作数组
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    int k=1;
    for(int i=0;i<=30;i++){
        t[i]=1;
        k*=2;
    }
    for(int i=1;i<=n;i++){
        int p=a[i];
        for(int j=30;i>=0;j--){
            if(p>=t[j]){
                b[i][j]=1;
                p-=t[i];
                c[j]++;
            }
        }
    }
    for(int i=30;i>=0;i--){
        if(c[i]<m)continue;
        if(c[i]>=m){
            bool f=0;
            for(int j=1;j<=n;j++){
                if(b[j][i]){
                    for(int k=0;k<=i;k++){
                        if(f==0)d[k]=b[j][i];
                        else d[k]=(d[k]&&b[i][j]);
                    }
                    f=1;
                }
            }
            long long ans=0;
            for(int j=0;j<i;j++){
                ans+=d[j]*t[j];
            }
            cout<<ans;
            return 0;
        }
    }
    return 0;
}
