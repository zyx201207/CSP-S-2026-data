#include<bits/stdc++.h>
using namespace std;
int a[500010];
int am[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int opp[m+1]={0};
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt=1;
    for(int i=1;i<=n;i++){//游戏次数
        for(int j=cnt;j<=n;j++){
            am[j]=a[j];
            for(int k=1;k<j;k++){
                if(am[k]==am[j]){
                    for(int o=k;o<j;o++) am[o]=0;
                }
            }
        }
        for(int j=cnt;j<=n;j++){
            opp[am[j]]++;
        }
        cnt++;
    }
    for(int i=1;i<=m;i++) cout<<opp[i]<<' ';
    return 0;
}
