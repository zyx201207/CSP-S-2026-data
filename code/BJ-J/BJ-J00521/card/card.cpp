#include<iostream>
using namespace std;
long long n,m,a[300005],cnt,num,sum[300005],fa;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        long long tong[300005]={0},qu[300005]={0};
        cnt=0;
        fa=0;
        for(int j=i;j<=n;j++){
            if(tong[a[j]]==0){
                qu[++cnt]=a[j];
                tong[a[j]]=cnt;
            }
            else {
                for(int z=tong[a[j]]+1;z<=cnt;z++){
                    tong[qu[z]]=0;
                }
                cnt=tong[a[j]];
            }
        }
        for(int j=1;j<=cnt;j++){
            sum[qu[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
