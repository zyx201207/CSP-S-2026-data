#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long int island[2000010],d,ans,minn=1e17;
long long int s[2000010],vis[2000010];
long long int res=0;
void check(int sta,int end,long long int ti){
	if(sta==end){
		s[ti]++;
		minn=min(minn,ti);
		return;
	} 
	for(int i=1; i<=n; i++){
		if(abs(island[sta]-island[i])<=d && !vis[i]){
			vis[i]=1;
			check(i,end,ti+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1; i<=n; i++) cin>>island[i];
		res=0;
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				if(island[j]-island[i]<=d) continue;
				minn=1e17;
				memset(s,0,sizeof(s));
				memset(vis,0,sizeof(vis));
				check(i,j,0);
				if(s[minn]==2) res++;
			}
		}
		cout<<res<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
