#include<bits/stdc++.h>
using namespace std;
long long n,m,a[3000010],i,ans=-1,j,mn=9999999999,mnn=1;
long long f,ccc;
string b[3000010];
string anss;
void dfs(long long x,long long cnt,long long f){
    if(f==m){
        ans=max(ans,cnt);
    }
    if(x==n+1){
        return;
    }
    if(f==0){
        dfs(x+1,a[x],f+1);
        dfs(x+1,0,0);
    }else{
        dfs(x+1,cnt&a[x],f+1);
        dfs(x+1,cnt,f);
    }
    return;
}
bool cmp(string x,string y){
    return x>y;
}
void lr(long long l,long long k){
    while(l!=0){
        b[k]=b[k]+(char)(48+l%2);
        l=l/2;
    }
    reverse(b[k].begin(),b[k].end());
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
        if(sqrt(a[i]+1)*sqrt(a[i]+1)!=a[i]+1){
            f=1;
        }
    }
    if(n<=20){
        dfs(1,0,0);
        cout<<ans;
    }else if(n<=2000){
        if(m==1){
            sort(a+1,a+n+1);
            cout<<a[n];
        }else if(m==2){
            for(i=1;i<=n;i++){
                for(j=1;j<i;j++){
                    ans=max(ans,a[i]&a[j]);
                }
            }
            cout<<ans;
        }else if(m==n){
            ans=a[1];
            for(i=2;i<=n;i++){
                ans=ans&a[i];
            }
            cout<<ans;
        }
    }else if(m=n-1){
        ccc=a[2];
        for(j=3;j<=n;j++){
            ccc=ccc&a[j];
        }
        ans=max(ccc,ans);
        for(i=2;i<=n;i++){
            ccc=a[1];
            for(j=1;j<=n;j++){
                if(i!=j){
                    ccc=ccc&a[j];
                }
            }
            ans=max(ans,ccc);
        }
        cout<<ans;
    }else if(f==0){
        sort(a+1,a+n+1);
        cout<<a[n];
    }else{
        for(i=0;i<n;i++){
            lr(a[i],i);
        }
        sort(b,b+n,cmp);
        for(i=0;i<mn;i++){
            int f=1;
            for(j=0;j<m;j++){
                mn=min(mn,(long long)b[j].size());
                if(b[j][i]=='0'){
                    f=0;
                    break;
                }
            }
            anss=anss+(char)(f+48);
        }
        for(i=anss.size()-1;i>=0;i--){
            if(anss[i]=='1'){
                ccc+=mnn;
            }
            mnn*=2;
        }
        cout<<ccc;
    }
    return 0;
}
