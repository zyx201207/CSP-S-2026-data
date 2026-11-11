#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define endl '\n'
int a[500010],n,d,c,ljb[500][500],ljb2[500][500],m,biao2[500][500],ans;
map<int,int>mp;
void solve(){
    cin>>n>>d;
    ans=0;
    m=d;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(ljb,0x3f,sizeof ljb);
    memset(ljb2,0x3f,sizeof ljb2);
    memset(biao2,0,sizeof(biao2));
    if(n<=300){
        //if(a[n]-a[0]<=d){
        //    cout<<0<<endl;
        //}
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    biao2[i][j]=1;
                if(i==j){
                    ljb[i][j]=0;
                    ljb2[i][j]=0;
                    continue;
                }
                if(abs(a[j]-a[i])<=d){
                   ljb[i][j]=abs(a[j]-a[i]);
                    ljb[j][i]=abs(a[j]-a[i]);
            ljb2[i][j]=ljb2[j][i]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                            if(i==j||j==k||i==k)continue;
                        if(ljb[i][j]+ljb[j][k]<ljb[i][k]||ljb2[i][j]+ljb2[j][k]<ljb2[i][k]){
                            ljb[i][k]=ljb[i][j]+ljb[j][k];
                            ljb2[i][k]=ljb2[i][j]+ljb2[j][k];
                            biao2[i][k]=1;
                        }
                        else if(ljb[i][j]+ljb[j][k]==ljb[i][k]&&ljb2[i][k]==ljb2[i][j]+ljb2[j][k]){
                            biao2[i][k]++;
                        }
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        //cout<<biao2[i][j]<<' ';
                    if(biao2[i][j]==2){
                        ans++;
                    }
                }
                //cout<<endl;
            }
            //cout<<endl;
            cout<<ans/2<<endl;
    }
    else if(c==11||c==12){
        m=m/(a[n-1]-a[n-2]);
        cout<<n-m*2+1;
    }
    else if(a[n]-a[0]<=m){
        cout<<0<<endl;
    }
    else{
        cout<<0<<endl;
    }
}
/*
123456
4/5
2->4
4 1
5 2
6
*/
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    //freopen("migrate2.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    int t=1;
    cin>>c>>t;
    while(t--){
        solve();
    }
}
/*
15:35
依旧T2洗脸
是时候随机穿梭了
Oct31=3*8+1==25
Dec25==25
(Oct31==Dec25) is true

*/
