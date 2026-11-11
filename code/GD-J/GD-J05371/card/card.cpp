#include<bits/stdc++.h>
using namespace std;
void moni(vector<int> &a,vector<int> &cnt,int n,int m){
	vector<int> q(m+1),li;
	for(int i=1;i<=n;i++){
		if(q[a[i]]){
			for(int j=li.size()-1;j>=q[a[i]];j--){ 
				q[li[j]]=0;
				li.pop_back();
			}
		}
		li.emplace_back(a[i]);
		q[a[i]]=li.size();
	}
	for(int i=1;i<=m;i++)
		if(q[i]){
			cnt[i]++;
			//cout<<i<<" ";
		}
	//cout<<'\n';
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1),cnt(m+1);
	bool flag=1;
	for(int i=1;i<=n;i++){ 
		cin>>a[i];
		if(i>1 && a[i]<a[i-1]) flag=0;
	}
	if(flag){
		for(int i=1;i<=n;i++) cnt[a[i]]=i;
		for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
		return;
	}
	for(int i=1;i<=n;i++){
		vector<int> b(n-i+2);
		for(int j=i;j<=n;j++) b[j-i+1]=a[j];
		moni(b,cnt,n-i+1,m);
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return 0;
}
