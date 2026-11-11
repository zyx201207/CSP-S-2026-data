#include<bits/stdc++.h>
#define rint long long
using namespace std;
const rint N=2e5+10,inf=0x3f3f3f3f;
int n,m;
int ans=-inf;
int vis[N];
int a[N];
void subset_enmeration(int x){
	if(x>n){
		int num=0,id=0,cnt=0;
		for(int i=1;i<=n;i++)
			if(vis[i]){
				num=a[i];
				id=i;
				break;
			}
        for(int i=1;i<=n;i++)
            if(vis[i])
                cnt++;
        if(cnt!=m)return;
        for(int i=1;i<=n;i++){
            if(id==i)continue;
            if(vis[i])
                num=num&a[i];
        }
        ans=max(num,ans);
		return;
	}
	vis[x]=1;
	subset_enmeration(x+1);
	vis[x]=0;
	subset_enmeration(x+1);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20)subset_enmeration(1);
	if(m==1)
        for(int i=1;i<=n;i++)
            ans=max(ans,a[i]);
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++)
            ans=ans&a[i];
    }
    if(m==2){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans=max(ans,a[i]&a[j]);
    }
    cout<<ans;
	return 0;
}
