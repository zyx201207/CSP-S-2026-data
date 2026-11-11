#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
bitset<N> isin;
int n,a[N],cnt[N],m;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool isup=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        isup&=(a[i]>=a[i-1]);
    }
    if(isup){
        for(int i=1;i<=n;i++){
            cnt[a[i]]++;
        }
        for(int i=1;i<=m;i++){
            cnt[i]+=cnt[i-1];
            cout<<cnt[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        isin.reset();
        for(int j=i;j<=n;j++){
            if(isin[a[j]]){
                for(int k=j-1;a[k]!=a[j];k--){
                    isin[a[k]]=0;
                }
            }
            isin[a[j]]=1;
        }
        for(int i=1;i<=m;i++){
            cnt[i]+=isin[i];
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
//CCF,I want CSP-J 300pts,please! CSP-S 150+pts,please!
//travel:[0,100] string[0,100] and[0,85] card[0,36]
//total: [0,100]+[0,100]+[0,85]+[0,36]=[0,331]
//Diffculty: [Red,Red] [Orange,Yellow] [Yellow,Green] [Yellow,Cyan]
