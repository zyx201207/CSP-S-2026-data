#include<bits/stdc++.h>
using namespace std;
int n,d,c,t;
void dfs(int begin,vector<int> idx,int jump,int check[],vector<int> a){
	
	if(begin+1>n) return;
	int end=begin;
	for(int i=begin+1;i<=n;i++){//cout<<1;
		if(a[i]<=a[begin]+d){
			end=i;
		}else{
			break;
		}
	}
	for(int i=begin+1;i<=end;i++){
		if(jump>check[i]&&check[i]>0) continue;
		if(check[i]==0){
			check[i]=jump;
			idx[i]+=1;
		}else{
			if(check[i]==jump){
				idx[i]++;
			}
		}
		dfs(i,idx,jump+1,check,a);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int ans;
	cin>>c>>t;
	while(t--){
		
		ans=0;
		cin>>n>>d;
		vector<int> a(n+1),idx(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int check[n+1]={};
			dfs(i,idx,0,check,a);
			for(int j=i+1;j<=n;j++){
				if(idx[j]==2){
					ans++;
				}
			}
			idx.clear();
		}
		cout<<ans<<'\n';
	}
	return 0;
}
