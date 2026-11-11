#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,t,n,d,minn,cnt,ed;
int a[N];
void dfs(int x,int step){
    if(x==ed){
        if(minn>step)
            cnt=1,minn=step;
        else if(minn==step)
            cnt++;
        return;
    }
    for(int i=x+1;i<=n;i++){
        if(a[i]-a[x]<=d && i<=ed)
            dfs(i,step+1);
        else
            break;
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        scanf("%d%d",&n,&d);
        int sum=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n-2;i++){
            for(int j=3;j<=n;j++){
                ed=j,cnt=0,minn=0x3f;
                dfs(i,0);
                if(cnt==2)
                    sum++;
            }
        }
        cout<<endl<<sum;
    }
    return 0;
}
