#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[1000050],sum,idx,b[1000050],ans,cnt,mn,mnn;
void dfs(int u,int v){
	if(sum>mnn){
		return;
	}
	if(u==v){
		b[idx++]=sum;
		mnn=min(mnn,sum);
		return;
	}
	for(int i=u+1;i<=v;i++){
		if(a[i]-a[u]<=d){
			sum++;
			dfs(i,v);
			sum--;
		}
		else{
			break;
		}
	}
}
int main(){
//	freopen("migrate3.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int u=1;u<=n-3;u++){
			for(int v=u+3;v<=n;v++){
				sum=0;
				idx=0;
				cnt=0;
				mn=1e9;
				mnn=1e9;
				dfs(u,v);
//				cout<<u<<' '<<v<<":\n";
				for(int i=0;i<idx;i++){
					if(b[i]<mn){
						cnt=1;
						mn=b[i];
					}
					else if(b[i]==mn){
						cnt++;
					}
//					cout<<b[i]<<' ';
				}
//				cout<<"\n******************\n\n\n";
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

