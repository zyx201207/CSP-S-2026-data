#include<iostream>
using namespace std;
int two[200005][32],n,m,cse[200005],mlen=-1,dx,a[200005],ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int b=a[i];
        while(b){
            two[i][++two[i][0]]=b%2;
            b/=2;
        }
        mlen=max(mlen,two[i][0]);
    }
    for(int i=mlen;i>=1;i--){
        dx=0;
        for(int j=1;j<=n;j++){
            if(two[j][i]==1&&cse[j]==mlen-i){
                dx++;
            }
        }
        if(dx>=m){
            for(int j=1;j<=n;j++){
                if(two[j][i]==1){
                    cse[j]++;
                }
            }
            ans+=(1<<(i-1));
        }
        if(dx<m){
            for(int j=1;j<=n;j++){
                cse[j]++;
            }
        }
    }
    cout<<ans;
    return 0;
}