#include<iostream>
#include<algorithm>
#include<cmath>//please give me 65 pts!!!
using namespace std;
int n,m,a[200005],v[200005],ans;
bool suba=1,subb=1;
void dfs(int x,int cnt,int num){
    if(cnt==m){
        ans=max(ans,num);
        return;
    }
    for(int i=x+1;i<=n;i++){
        dfs(i,cnt+1,num&a[i]);
    }
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(log2(a[i])!=(int)log2(a[i])) suba=false;
        if(a[i]!=i-1) {
            subb=false;
            cout<<i;
        }
    }
    if(m==1){//#6
        int mx=-2e9;
        for(int i=1;i<=n;i++){
            mx=max(mx,a[i]);
        }
        cout<<mx;
        return 0;
    }
    else if(m==n){//#7
        int t=a[1];
        for(int i=2;i<=n;i++){
            t=t&a[i];
        }
        cout<<t;
        return 0;
    }
    else if(suba==true){//#13
        sort(a+1,a+n+1,cmp);
        int num=2147483647;
        for(int i=1;i<=m;i++){
            num=num&a[i];
        }
        cout<<num;
    }
    else if(subb==true){//#14,15
        sort(a+1,a+n+1,cmp);
        int num=2147483647;
        for(int i=1;i<=m;i++){
            num=num&a[i];
        }
        cout<<num;
    }
    else if(pow(n,m)<=50000000){//#1-5,#8-10
        for(int i=1;i<=n;i++){
            dfs(i,1,a[i]);
        }
        cout<<ans;
    }
    else{//rp++
        sort(a+1,a+n+1,cmp);
        int num=2147483647;
        for(int i=1;i<=m;i++){
            num=num&a[i];
        }
        cout<<num;
    }
    return 0;
}
