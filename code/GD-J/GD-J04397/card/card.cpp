#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],f;
unordered_map<int,int>mp;
vector<int>v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i])f=0;
	}
	for(int i=n;i>0;i--){
		if(mp.count(a[i])&&mp[a[i]]){
			int x;
			for(int j=v.size()-1;j>=0;j--){
				mp[v[j]]=0;
				if(v[j]==a[i]){
					x=j;
					break;
				}
			}
			v.erase(v.begin()+x,v.end());
		}
		mp[a[i]]=1;
		v.push_back(a[i]);
		for(int x:v)ans[x]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
