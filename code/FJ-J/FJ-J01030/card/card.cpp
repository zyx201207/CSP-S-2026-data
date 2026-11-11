#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],l[500005],cnt[500005],ru[500005],v[500005],vis[500005];
int k[500005];
vector<int>ve[500005];
void dfs(int p){
//	cout<<p<<endl;
	for(int i=0;i<ve[p].size();i++){
		if(vis[ve[p][i]]==0){
			vis[ve[p][i]]=1;
			dfs(ve[p][i]);
	//		cout<<ru[ve[p][i]]<<endl;
			ru[p]+=ru[ve[p][i]];
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ru[i]=1;
	}
	for(int i=n;i>=1;i--){
	//	cout<<l[a[i]]<<endl;
		if(l[a[i]]!=0){
			ve[l[a[i]]].push_back(i);
			v[i]=1;
			//ru[l[a[i]]]++;
		}else{
			if(i!=n){
				
			ve[i+1].push_back(i);
			}
			l[a[i]]=i;
			
		}
	}
	vis[n]=1;
	dfs(n);
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			k[a[i]]+=ru[i];
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<k[i]<<" ";
	}
	return 0;
}
