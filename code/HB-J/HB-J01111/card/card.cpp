#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=2e5+7;
int n,m,c[N],t[N],ans[N],tail=0,cnt[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++){
        memset(cnt,0,sizeof cnt);
        tail=0;
        for(int j=i;j<=n;j++){
            int flag=0;

            for(int k=1;k<=tail;k++){
                if(c[j]==t[k])tail=k,flag=1;
            }
            if(!flag)t[tail++]=c[j];
        }
        for(int j=1;j<=tail;j++)cnt[t[j]]=1;
        for(int j=1;j<=m;j++)ans[j]+=cnt[j];
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
    return 0;
}
