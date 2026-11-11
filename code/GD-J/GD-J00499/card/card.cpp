#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1),id[k+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		id[a[i]].push_back(i);
	}
	vector<int> last;
	
	vector<int> ans(k+1),e(k+1),p(k+1);
	for(int i=n;i>=1;i--)if(!ans[a[i]]){
		ans[a[i]]=i,last.push_back(i),e[i]=a[i],p[a[i]]=i;
	}
	
	
	sort(last.begin(),last.end());
//	for(int i=0;i<n;i++)cout<<last[i]<<" ";
	vector<int> cnt(k+1);
//	cout<<lower_bound(last.begin(),last.end(),1)-last.begin();
	for(int i=1;i<n;i++){
		if(i==p[a[i]])continue;
		int next=id[a[i]][++cnt[a[i]]];
		int l=lower_bound(last.begin(),last.end(),i)-last.begin();
		int r=upper_bound(last.begin(),last.end(),next)-last.begin();
		
		if(l==n+1)continue;
		for(;l<=r;l++){
			ans[e[l]]-=i;
		}
	}
	for(int i=1;i<=k;i++)cout<<ans[i]<<" ";
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
}
