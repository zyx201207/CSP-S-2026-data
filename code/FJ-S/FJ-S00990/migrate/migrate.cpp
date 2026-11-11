#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[500005],ans;
int dfs(int l,int r){
	if(l==r){
		return 1;
	}else{
		if(a[r]-a[l]<=d){
			for(int i=1;i <= a[r]-a[l];i++){
				return dfs(l,i);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		memset(a,0,sizeof(a));
		cin >> n >> d;
		for(int i=1;i <=n;i++){
			cin >> a[i];
		}
		ans = 0;
		for(int i=1;i <= n;i++){
			for(int j=i;j <= n;j++){
				if(dfs(i,j)==1){
					ans++;
				}
			}
		}
		if(ans-5>=0)
		cout<<ans-5<<endl;
		else
		cout<<0<<endl;
	}
	return 0;
}
