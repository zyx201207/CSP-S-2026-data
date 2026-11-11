#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,m,a[N],cnt,vis[N],b[N],sum,res,num;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        res=i;
        for(int j=i;j<=n;j++){
            b[j]=1;
            sum=0;
            num=0;
            for(int k=res;k<j;k++){
                if(a[k]==a[j]&&b[k]!=0){
                    sum=1;
                    b[k]=0;
                }
                if(sum==1){
                    b[k]=0;
                }
                if(b[k]==0&&num==0){
                    res=k;
                }else if(b[k]!=0){
                    num++;
                }
            }
        }
        for(int j=res;j<=n;j++){
            if(b[j]!=0){
                vis[a[j]]++;
                b[j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<vis[i]<<" ";
    }
    return 0;
}
