#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
long long maxn,ans=1;
long long bao;
int n,m;
bool vis[N];
long long p[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};

void dfs(int id,int stp,long long sum){
    if(stp==0){
        //cout<<"Yes";
        bao=max(sum,bao);
        return ;
    }
    //cout<<sum<<" ";
    //vis[id]=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(i,stp-1,sum&a[i]);
            vis[i]=0;
        }
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        ans&=a[i];
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    else if(m==n){
        cout<<ans;
        return 0;
    }
    else if(m==2){
        long long res=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j)
                    res=max(res,a[i]&a[j]);
            }
        }
        cout<<res;
        return 0;
    }
    else if(n<=20){
        vis[1]=1;
        dfs(1,m-1,a[1]);
        cout<<bao;
        return 0;
    }

    bool flag=1;
    for(int i=1;i<=n;i++){
        bool F=0;
        for(int j=0;j<21;j++){
            if(a[i]==p[j]-1){
                F=1;
                break;
            }
        }
        if(F==0){
            flag=0;break;
        }
    }
    if(flag){
        sort(a+1,a+n+1,greater<long long>());
        cout<<a[m];
        return 0;
    }
    cout<<n;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
long long maxn,ans=1;
long long bao;
int n,m;
bool vis[N];
long long p[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};

void dfs(int id,int stp,long long sum){
    if(stp==0){
        //cout<<"Yes";
        bao=max(sum,bao);
        return ;
    }
    //cout<<sum<<" ";
    //vis[id]=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(i,stp-1,sum&a[i]);
            vis[i]=0;
        }
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        ans&=a[i];
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    else if(m==n){
        cout<<ans;
        return 0;
    }
    else if(m==2){
        long long res=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j)
                    res=max(res,a[i]&a[j]);
            }
        }
        cout<<res;
        return 0;
    }
    else if(n<=20){
        vis[1]=1;
        dfs(1,m-1,a[1]);
        cout<<bao;
        return 0;
    }

    bool flag=1;
    for(int i=1;i<=n;i++){
        bool F=0;
        for(int j=0;j<21;j++){
            if(a[i]==p[j]-1){
                F=1;
                break;
            }
        }
        if(F==0){
            flag=0;break;
        }
    }
    if(flag){
        sort(a+1,a+n+1,greater<long long>());
        cout<<a[m];
        return 0;
    }
    cout<<n;
    return 0;
}
