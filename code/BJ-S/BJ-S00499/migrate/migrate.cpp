#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e6+10;
int c,T,n,d,mn,num,x[N];
void dfs(int t,int y,int cnt){
    if(t==y){
        if(mn>cnt)
            mn=cnt,num=0;
        if(cnt==mn)
            num++;
        return;
    }
    for(int i=t+1;i<=n;i++){
        if(x[i]-x[t]<=d)
            dfs(i,y,cnt+1);
    }
}
bool check(int t,int y){
    num=0,mn=inf;
    dfs(t,y,0);
    return num==2;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        int cnt=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(i!=j&&check(i,j))
                    cnt++;
        cout<<cnt<<'\n';
    }
    return 0;
}