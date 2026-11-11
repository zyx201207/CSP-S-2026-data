#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005,V=2147483647;
string _10_to_2_(int x){
    string ans="";
    while(x){
        string y;
        if(x&1){
            y="1";
        }
        else{
            y="0";
        }
        ans=y+ans;
        x=x>>1;
    }
    return ans;
}
int n,m,a[N],b[N],f[(1LL<<21)+5];
string bit[N];
int dfs(int p,int cnt,int res){
    if(cnt==m){
        return res;
    }
    if(p==n){
        return 0;
    }
    if(n-p<m-cnt){
        return 0;
    }
    int sum=0;
    for(int i=p+1;i<=n;i++){
        sum=max(sum,dfs(i,cnt+1,res&a[i]));
    }
    return sum;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxa=0;
    bool flagA=1,flagB=1;
    string nn=_10_to_2_(n);
    flagB&=nn[0]=='1';
    for(int i=1;i<nn.size()&&flagB;i++){
        flagB&=nn[i]=='0';
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        bit[i]=_10_to_2_(a[i]);
        for(int j=0;j<bit[i].size()&&flagA;j++){
            flagA&=bit[i][j]=='1';
        }
        flagB&=a[i]==i-1;
        maxa=max(maxa,a[i]);
    }
    int ans=0;
    if(n<=20){
        ans=dfs(0,0,V);
    }
    else if(m==1){
        ans=maxa;
    }
    else if(m==n){
        ans=V;
        for(int i=1;i<=n;i++){
            ans&=a[i];
        }
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    else if(m==n-1){
        int l=V;
        for(int i=1;i<=n;i++){
            b[i]=l;
            l&=a[i];
        }
        int r=V;
        for(int i=n;i>=1;i--){
            ans=max(ans,b[i]&r);
            r&=a[i];
        }
    }
    else if(flagA){
        for(int i=1;i<=n;i++){
            if(++f[bit[i].size()]==m){
                ans=max(ans,(1LL<<_10_to_2_(a[i]).size())-1);
            }
        }
    }
    else if(flagB&&0){

    }
    else if(maxa<=(1LL<<10)&&maxa<=4){
        for(int i=1;i<=n;i++){
            for(int s=a[i];s;s=(s-1)&a[i]){
                if(++f[s]==m){
                    ans=max(ans,s);
                }
            }
        }
    }
    else{
        ans=dfs(0,0,V);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
