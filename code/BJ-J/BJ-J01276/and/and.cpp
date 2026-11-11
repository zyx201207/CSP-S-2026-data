# include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int vis[N];
long long pw[40];
long long ans=0;
void init(){
    pw[0]=1;
    for(int i=1;i<=32;i++){
        pw[i]=pw[i-1]*2;
    }
}
int cont_size(int x){
    int cnt=0;
    while(x!=0){
        cnt++;
        x>>=1;
    }
    return cnt;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    init();
    int maxn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>maxn)maxn=a[i];
    }
    int siz=cont_size(maxn)-1;
    for(int i=siz;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if((a[j]>>i)&1&&!vis[j]){
                cnt++;
            }

        }
        if(cnt>=m){
            ans+=pw[i];
            for(int j=1;j<=n;j++){
                if(!((a[j]>>i)&1))vis[j]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
