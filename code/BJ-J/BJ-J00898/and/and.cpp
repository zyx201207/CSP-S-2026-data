#include<iostream>
#include<cmath>
#define int long long
using namespace std;
int n,m;
int mx;
int vis[200005];
int p[200005];
string s[200005];
void dfs(int x,long long y){
    if(x>m){
        mx=max(mx,y);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            if(x==1){
                dfs(x+1,p[i]);
            }
            else{
                dfs(x+1,y&p[i]);
            }
            vis[i]=0;
        }
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int mxl=0;
    int temp;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        int x=p[i];
        int len=0;
        while(x){
            len++;
            if(x%2==0){
                s[i]+="0";
            }
            else{
                s[i]+="1";
            }
            x/=2;
        }
        if(len>mxl){
            mxl=len;
            temp=i;
        }
    }
    int flag=0;
    int scl=0;
    for(int i=1;i<=n;i++){
        if(i!=temp&&s[i].size()==mxl){
            flag=1;
            break;
        }
        if(i!=temp){
            int l=s[i].size();
            scl=max(scl,l);
        }
    }
    if(flag==0){
        p[temp]=0;
        for(int i=1;i<=scl;i++){
            if(s[temp][i]=='1'){
                p[temp]+=pow(2,i-1);
            }
        }
    }
    dfs(1,1);
    cout<<mx;
    return 0;
}
