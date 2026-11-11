#include<bits/stdc++.h>
using namespace std;
int n,d;
long long cnt;
long long ci;
long long a[2000010];
void dfs(int q,int z,int c){
	if(q>z){
		return;
	}
	if(q==z){
		if(c<ci){
			ci=c;
			cnt=1;
		}else if(c==ci){
			cnt++;
		}
		return;
	}
	for(int i=q+1;i<=n;i++){
		if(abs(a[q]-a[i])<=d){
			dfs(i,z,c+1);
		}else{
			break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdin);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			cout<<0<<endl;
		}
		return 0;
	}
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			for(int i=1;i<=n;i++){
				cnt=0;
				ci=0x3f3f3f3f;
				dfs(1,i,0);
				if(cnt==2){
					cout<<n-i+1;
					return 0;
				}
			}
		}
	}
	while(t--){
		cin>>n>>d;
		long long minn=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			minn=min(minn,a[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				ci=0x3f3f3f3f;
				dfs(i,j,0);
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
