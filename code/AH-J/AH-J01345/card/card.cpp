#include<bits/stdc++.h>
using namespace std;
int a[500010];
int o[500010];
int last[300010];
unordered_map<int,vector<int> >mp;
unordered_map<int,int> mp1;
int ans[300010];
int of(int x){
	if(o[x]==0)return x;
	return o[x]=of(o[x]);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >>n>>m;
	for(int i=1;i<=n;i++)
		cin >>a[i];
	for(int i=n;i>=1;i--){
		if(last[a[i]]==0){
			mp[i]=mp[of(i+1)];
			mp[i].push_back(a[i]);
		}
		else{
			o[i]=last[a[i]];
		}
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		mp1[of(i)]++;
	}
	vector<int> t;
	for(unordered_map<int,vector<int> >::iterator i=mp.begin();i!=mp.end();i++){
		int k=i->first;
		t=i->second;
		int y=mp1[k];
		for(int j=0;j<(int)t.size();j++){
			ans[t[j]]+=y;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
