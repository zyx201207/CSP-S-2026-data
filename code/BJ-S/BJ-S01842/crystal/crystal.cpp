#include<bits/stdc++.h>
using namespace std;
const long long MAXN=500010;
long long n,m,pre,now,ans,x=1,y=2,flag=0;
long long a[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(x=1;x<=n-1;x++){
        if(x>=y){
            y++;
            now=a[y]-a[x];
        }else if(y==x+1){
            now=a[y]-a[x];
        }else now=pre-(a[y]-a[x-1]);
        pre=now;
        if(now<=m){
            if(y-x+1>ans) ans=y-x+1;
            for(y=y+1;y<=n;y++){
                now=pre+(a[y]-a[y-1])*(y-x);
                if(now<=m){
                    if(y-x+1>ans) ans=y-x+1;
                    pre=now;
                    if(y==n) flag=1;
                    continue;
                }else{
                    y--;
                    break;
                }
            }
        }else continue;
        if(flag==1) break;
    }
    cout<<ans<<endl;
    return 0;
}
