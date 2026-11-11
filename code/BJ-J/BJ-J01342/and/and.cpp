#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[10000],ans,maaxx=0;
int pow(int a,int b){
    int ans=1;
    for(int i=1;i<=b;i++) ans*=a;
    return ans;
}
bool isitpow(int a){
    for(int i=0;i<=25;i++){
        if(a==pow(2,i));
        return 1;
    }
    return 0;
}
bool visit[2000000];
int ans15,total15;
int path[2000000];
void dfs(int x){
    if(x>m){
        for(int i=1;i<=m;i++){
            if(i==1) ans15=path[i];
            else ans15=ans15&path[i];
        }
        total15=max(total15,ans15);
        return;
    }
    for(int i=1;i<=n;i++){
        if(visit[a[i]]) continue;
        visit[a[i]]=1;
        path[x]=a[i];
        dfs(x+1);
        visit[a[i]]=0;
    }
}
bool checkforA,checkfor1617;
int save1617[4];//0,1,2,3 dui ying zhe ge zi de ge shu
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!isitpow(a[i])) checkforA=1;
        if(a[i]>=4) checkfor1617=1;
        if(i==1) ans=a[i];
        else ans=ans&a[i];
        maaxx=max(maaxx,a[i]);
    }
    if(!checkfor1617){
        for(int i=1;i<=n;i++) save1617[a[i]]++;
        m-=save1617[3];
        if(m<=0){
            cout<<3;
            return 0;
        }
        if(save1617[2]>=m){
            cout<<2;
            return 0;
        }else if(save1617[1]>=m){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    if(n<=20||m==n-1||m==2){
        dfs(1);
        cout<<total15;
        return 0;
    }
    if(m==n){
        cout<<ans;
        return 0;
    }
    if(m==1){
        cout<<maaxx;
        return 0;
    }
    if(!checkforA){
        sort(a+1,a+1+n,greater<int>());
        cout<<a[m];
        return 0;
    }

    return 0;
}
