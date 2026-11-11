#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],cnt,ans[100010],ci;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        cnt=0;ci=1;
        long long b[100010][5]={0},c[100010]={0};

        for(long long j=i;j<=n;j++){
            b[a[j]][1]++;
            c[ci-cnt]=a[j];
            if(b[a[j]][1]==2){
                //cout<<' '<<" b:"<<b[a[j]][2]<<"  ";
                for(long long x=ci-cnt;x>b[a[j]][2];x--){
                    c[x]=0;
                    cnt++;
                }
                b[a[j]][2]=ci-cnt;
                b[a[j]][1]=1;
                c[ci-cnt]=a[j];
            }
            else{
                b[a[j]][2]=ci-cnt;
            }
            ci++;
            /*for(long long t=1;t<=n;t++){
                cout<<c[t]<< " ";
            }
            cout<<endl;*/
        }
        for(long long j=1;j<=n;j++){
            ans[c[j]]++;
        }
    }
    for(long long j=1;j<=m;j++){
        cout<<ans[j]<< " ";
    }
    return 0;
}
