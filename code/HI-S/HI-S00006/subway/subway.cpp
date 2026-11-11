#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005];
vector<long long>a[505],b[505],cnt[500005];
long long s[5005][5005];
long long arr[500005][2]={0};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(c==20||c==21){
		for(int i=1;i<=n;i++){
			int u;
			cin>>u;
			while(u--){
				int x,y;
				cin>>x>>y;
				arr[x][i-1]=y;
			}
		}
		long long mi=1e10;
		for(int i=1;i<=m;i++){
			if(arr[i][1]>0&&arr[i][0]>0){
				mi=min(mi,arr[i][1]+arr[i][1]);
			}
			if(arr[i][0]==0){
				arr[i][0]=1e10;
			}
			if(arr[i][1]==0){
				arr[i][1]=1e10;
			}
		}
		while(q--){
			int u,v;
			cin>>u>>v;
			long long ans1=arr[u][1]+arr[v][1];
			long long ans2=arr[u][1]+arr[v][0]+mi;
			long long ans3=arr[u][0]+arr[v][1]+mi;
			long long ans4=arr[u][0]+arr[v][0];
			long long ans=min(ans1,ans2);
			ans=min(ans,ans3);
			ans=min(ans,ans4);
			cout<<(long long)(ans+w[u]+w[v])<<'\n';
		}
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		int u;
		cin>>u;
		while(u--){
			int aa,bb;
			cin>>aa>>bb;
			a[i].push_back(aa);
			b[i].push_back(bb);
			cnt[aa].push_back(i);
		}
	}
	for(int i=0;i<=m;i++){
		for(int j=0;j<=m;j++){
			s[i][j]=2e9;
			if(i==j){
				s[i][j]=0;
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(auto x:cnt[i]){
//			long long cc=0;
//			for(int j=0;j<a[x].size();j++){
//				if(a[x][j]==i){
//					cc+=b[x][j];
//					break;
//				}
//			}
//			for(int j=0;j<a[x].size();j++){
//				if(a[x][j]!=i){
//					s[a[x][j]][i]=min(s[a[x][j]][i],cc+b[x][j]);
//					s[i][a[x][j]]=min(s[i][a[x][j]],cc+b[x][j]);
//					break;
//				}
//			}
//		}
//	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size()-1;j++){
			for(int k=j+1;k<a[i].size();k++){
				s[a[i][j]][a[i][k]]=min(s[a[i][j]][a[i][k]],b[i][j]+b[i][k]);
				s[a[i][k]][a[i][j]]=min(s[a[i][k]][a[i][j]],b[i][j]+b[i][k]);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			if(s[i][j]==2e9){
//				cout<<-1<<" ";
//			}
//			else{
//				cout<<s[i][j]<<" ";
//			}
//		}
//		cout<<'\n';
//	}
	for(int u=0;u<m;u++){
		int v=false;
		for(int i=1;i<m;i++){
			for(int j=i+1;j<=m;j++){
				for(int k=1;k<=m;k++){
					if(k==j||k==i){
						continue;
					}
					if(!v&&s[j][i]>s[i][k]+s[j][k]){
						v=true;
					}
					s[j][i]=min(s[j][i],s[i][k]+s[j][k]);
					s[i][j]=min(s[i][j],s[i][k]+s[j][k]);
				}
			}
		}
		if(!v){
			break;
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			if(s[i][j]==2e9){
//				cout<<-1<<" ";
//			}
//			else{
//				cout<<s[i][j]<<" ";
//			}
//		}
//		cout<<'\n';
//	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<(long long)(s[u][v]+w[u]+w[v])<<"\n";
	}
	return 0;
}
