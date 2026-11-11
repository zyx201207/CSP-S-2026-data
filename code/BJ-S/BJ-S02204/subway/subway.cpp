#include<bits/stdc++.h>
using namespace std;
int c;
int n,m,d,q;
long long tio[15];//in and out station
int k[5];
int station[5][13];
int t[5][13];
int plan[3][13];
int ans;
int change[13];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>station[i][j]>>t[i][j];
            change[station[i][j]]++;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>plan[1][i]>>plan[2][i];
    }
    for(int i=1;i<=n;i++)
    for(int i=1;i<=q;i++){
        int ps1,ps2,pe1,pe2;
        for(int i=1;i<=n;i++){
            for(int j=1;i<=k[i];j++){
                if(station[i][j]==plan[1][i]){
                    ps1=i;
                    ps2=j;
                }
                if(station[i][j]==plan[2][i]){
                    pe1=i;
                    pe2=j;
                }
            }
        }
        ans=ans+t[station[ps1][ps2]];
        ans+=t[station[pe1][pe2]];
    }
    cout<<ans;
    return 0;
}

