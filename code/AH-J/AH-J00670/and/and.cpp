#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
int n,m;
int a[200005];
int step[25];
int res=-1;
bool vis[200005];
int t=-1;
int tong[5];
string s[200005];
vector<int> g;
void dfs(int x,int s){
    if(x==n+1){
        if(s==m){
            int ans=step[1];
            for(int i=2;i<=s;i++){
                ans&=step[i];
            }
            res=max(res,ans);
        }
        return ;
    }
    step[s+1]=a[x];
    dfs(x+1,s+1);
    dfs(x+1,s);
}
bool check(int x){
    for(int i=0;i<=30;i++){
        int t=(int)(pow(2,i));
        if(t==x)    return 1;
    }
    return 0;
}
bool cmp(int a,int b){
    return a>b;
}
string fun(int x){
    string ans="";
    while(x){
        ans+=(x%2+'0');
        x/=2;
    }
    reverse(ans.begin(),ans.end());
    while(ans.size()<30){
        ans="0"+ans;
    }
    return ans;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i];
    bool f=1;
    for(int i=1;i<=n;i++){
        f=f&check(a[i]+1);
        t=max(t,a[i]);
    }
    if(n<=20){//1~5
        dfs(1,0);
        cout<<res;
    }else if(m==1){//6
        for(int i=1;i<=n;i++){
            res=max(res,a[i]);
        }
        cout<<res;
    }else if(m==n){//7
        res=a[1];
        for(int i=2;i<=n;i++){
            res&=a[i];
        }
        cout<<res;
    }else if(m==2){//8~10
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                res=max(res,(a[i]&a[j]));
            }
        }
        cout<<res;
    }else if(f){//13
        sort(a+1,a+n+1,cmp);
        cout<<a[m];
    }else if(n<=10000&&m==n-1){//11~12 O(n^2)
        int ans=-1;
        for(int i=1;i<=n;i++){
            vis[i]=1;
            if(i!=1)    res=a[1];
            else res=a[2];
            if(i==1){
                vis[2]=1;
            }
            for(int j=2;j<=n;j++){
                if(!vis[j]){
                    res&=a[j];
                }
                if(res<ans) break;
            }
            ans=max(ans,res);
            vis[i]=0;
            if(i==1)    vis[2]=0;
        }
        cout<<ans;
    }else if(t<=4){//16~17
        for(int i=1;i<=n;i++){
            tong[a[i]]++;
        }
        if(tong[4]>=m){
            cout<<4;
        }else if(tong[3]>=m){
            cout<<3;
        }else if(tong[3]+tong[2]>=m){
            cout<<2;
        }else if(tong[3]+tong[1]>=m){
            cout<<1;
        }else{
            cout<<0;
        }
    }else if(check(n)){//14~15
        res=a[n];
        for(int i=n-1;i>=n-m+1;i--){
            res&=a[i];
        }
        cout<<res;
    }else{//18~20
        for(int i=1;i<=n;i++){
            s[i]=fun(a[i]);
            //cout<<s[i]<<' ';
            vis[i]=1;
        }
        for(int i=0;i<=29;i++){
            int cnt=0;
            for(int j=1;j<=n;j++){
                if(vis[j]&&s[j][i]=='1'){
                    cnt++;
                }
            }
            if(cnt>=m){
                for(int j=1;j<=n;j++){
                    if(vis[j]&&s[j][i]=='0'){
                        vis[j]=0;
                    }
                }
            }
            if(cnt==m){
                res=2147483647;
                for(int j=1;j<=n;j++){
                    if(vis[j])  res&=a[j];
                }
                cout<<res;
                return 0;
            }
        }
        res=2147483647;
        for(int i=1;i<=n;i++){
            if(vis[i])  res&=a[i];
        }
        cout<<res;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
