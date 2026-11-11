#include<bits/stdc++.h>
using namespace std;
long long l,n,m,a[500010],ans[500010],w[500010],vis[500010];
vector<long long> v;
int main(){
	freopen("card2.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(w,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			v.push_back(a[j]);
			if(vis[a[j]]!=0){
				for(long long k=w[a[j]];k<=v.size();k++) vis[v[k]]--;
				for(long long k=w[a[j]];k<=v.size();k++) v.pop_back();
			}
			vis[a[j]]++;
			w[a[j]]=v.size();
		}
		for(int j=1;j<=m;j++){
			if(vis[j]!=0) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
