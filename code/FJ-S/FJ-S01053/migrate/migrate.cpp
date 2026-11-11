#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],ans,cnt,s,minn;
void dfs(int x,int l){
	if(x==s){
		if(l<minn){
			minn=l;
			cnt=1;
		}else if(l==minn){
			cnt++;
		}
	}
	for(int i=x+1;i<=n&&a[x]+d>=a[i];i++){
		dfs(i,l+1);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		minn=INT_MAX;
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				s=j;
				dfs(i,0); 
				if(cnt==2){
					ans++;
				} 
				cout<<cnt;
			}
		}
		cout<<ans<<endl;
	}
}
