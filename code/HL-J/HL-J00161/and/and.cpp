#include<bits/stdc++.h>
using namespace std;
#define MAXN 200000
int a[MAXN];    int n,m;
bool check[MAXN];
int ans=0;
void dfs(int andx,int deep){
    if(deep>=m){
        if(ans<=andx) ans=andx;
        //for(int i=1;i<=n;i++) cout <<check[i] <<' ';
        //cout << '\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(check[i]==0){
            //if((a[i]&andx)<ans) continue;

            check[i]=1;
            dfs((a[i]&andx),deep+1);
            check[i]=0;
        }
    }

}
bool cmp(int a,int b){
    int c=0;
    while(a>>=1){
            if(a&1==1) c++;
    }
    int d=0;
    while(b>>=1){
            if(b&1==1) d++;
    }
    return c>d;
    }
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    //sort(a+1,a+n+1,cmp);
    //for(int i=1;i<=n;i++) cout <<a[i] << ' ';
    for(int i=1;i<=n;i++){
        int start=a[i];
        check[i]=1;
        dfs(a[i],1);
        check[i]=0;
        //cout << ans <<'\n';
    }

    cout <<ans <<' ';
    return 0;
}
