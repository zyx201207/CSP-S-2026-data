#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=2e5+10;
const int maxk=(1<<30)+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
bool a[maxn][40];
bool f[maxn];
int n,m;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    //n=m=2e5;
    int t,tmp,k=0;
    for(int i=1;i<=n;i++){
        cin>>t;
        //t=0xfffffff;
        tmp=0;
        while(t){
            a[i][tmp++]=t&1;
            t>>=1;
        }
/*
        for(int j=1;j<tmp;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
*/
        k=max(k,tmp-1);
        f[i]=1;
    }
    int cnt,ans=0;
    for(int j=k;j>=0;j--){
        cnt=0;
        for(int i=1;i<=n;i++){
            if(!f[i]){
                continue;
            }
            if(a[i][j])cnt++;
        }
        if(cnt>=m){
            ans+=(1<<j);
            for(int i=1;i<=n;i++){
                if(!a[i][j]){
                    f[i]=0;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
