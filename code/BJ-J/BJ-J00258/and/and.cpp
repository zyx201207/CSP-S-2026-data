#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+10;
int n,m;
long long a[maxn],exe[32];
bool b[maxn][33];
bool ans[33];//recording the answer after dfs and need to clear
long long maxx;//6 3 31 127 63 15 127 63
bool check(){
    for(int i=1;i<=n;i++){
        bool flag=false;
        for(int j=1;j<=30;j++){
                //cout<<a[i]<<" "<<exe[j]-1<<"__ ";
            if(a[i]==exe[j]-1){
                //cout<<i<<"#1 ";
                flag=true;
                break;
            }
        }
        if(!flag){
            //cout<<i<<"#2 ";
            return false;
        }
        //cout<<endl;
    }
    return true;
}
bool vis[maxn];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        int x=a[i];
        int cnt=0;
        while(x!=0){
            cnt++;
            if(x%2){
                b[i][cnt]=1;
            }
            x/=2;
        }
    }
    for(int i=1;i<=30;i++){
        exe[i]=pow(2,i);
    }
    /*for(int i=1;i<=9;i++){
        cout<<exe[i]<<" ";
    }
    cout<<endl;*/
    if(m==1){
        cout<<maxx;
        return 0;
    }
    if(m==n){
        for(int i=1;i<=33;i++){
            ans[i]=b[1][i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=33;j++){
                ans[j]=ans[j]&&b[i][j];
            }
        }
        long long ans0;
        for(int i=1;i<=33;i++){
            if(!ans[i]){
                continue;
            }
            ans0+=pow(2,i-1);
        }
        cout<<ans0;
    }
    if(check()){//do not need to spread
        sort(a+1,a+1+n);
        cout<<a[n+1-m];
    }
    return 0;
}