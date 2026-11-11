#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m;
bool vis[N];
struct st{
    bool b[32];
    int n,s;
    st(){memset(b,0x00,sizeof b),n=0,s=0;}
}a[N];
vector<int> v[N];
void fst1(int n,int xb){
    int cnt=0,s;
    while(n){
        if(n&1)a[xb].b[cnt]=1,s++;
        cnt++;
        n>>=1;
    }
    a[xb].s=s;
    return;
}
bool cmp(st a,st b){
    return a.n>b.n;
}
bool b[33][N];
int dfs(int now){
    int locked=-1;
    for(int i = now;i >= 0;i--){
        int cnt=0;
        if(v[i].size()>=m){
            for(auto u:v[i]){
                b[i][u]=b[now+1][u];
                if(b[i][u])cnt++;
                //cout << b[i][u] << " ";
            }
            //cout << endl;
            if(cnt>=m){
                locked=i;
                    //cout << locked << " locked\n";
                break;
            }
        }
    }
    if(locked!=-1)return (1<<locked)|dfs(locked-1);
    else return 0;
}
void output(){
    for(int i = 0;i <= 32;i++){
        for(auto u:v[i])cout << u << " ";
        cout << endl;
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> a[i].n;
    for(int i = 1;i <= n;i++)fst1(a[i].n,i);
    //sort(a+1,a+1+n,cmp);
    //cout << a[1].n << endl;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 32;j++){
            if(a[i].b[j])v[j].push_back(i);//cout << a[i].b[j] << " ";
        }
        //cout << endl;
    }
    int ans=0;/*
    for(int i = 31;i >= 0;i--){
        if(v.size()>=m){
            for(auto u:v[i]){
                b[i][u]=1;
            }
        }
    }*/
    for(int i = 1;i <= n;i++)b[32][i]=1;
    cout << dfs(31) << endl;
    //output();
    return 0;
}
