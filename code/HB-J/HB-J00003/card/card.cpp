#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>v;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	vector<int>la(m+1,-1);
	int sum=0;
	for(int i=n-1;i>=0;i--){
		if(la[v[i]]==-1){
			la[v[i]]=i;
			sum++;
		}
		if(sum==m)break;
	}
	vector<int>ans(m+1,0);
	for(int i=0;i<n;i++){
		int pos=i;
		vector<bool>vis(m+1,false);
		while(pos<n){
			if(!vis[v[pos]]){
				vis[v[pos]]=true;
				ans[v[pos]]++;
			}
			if(pos!=la[v[pos]])pos=la[v[pos]];
			else pos++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
