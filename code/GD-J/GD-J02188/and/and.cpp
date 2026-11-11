#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,a[200010],ans;
vector<int>cnt[32];
set<int>st,newst;
void solve(){
	for(int i=1;i<=n;i++)st.insert(i);
	for(int i=29;i>=0;i--){
		if((int)cnt[i].size()<m)continue;
		newst.clear();
		for(int x:cnt[i]){
			if(st.count(x))newst.insert(x);
		}
		if((int)newst.size()>=m){
			st.clear();
			for(int x:newst)st.insert(x);
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,base,t;i<=n;i++){
		cin>>a[i];
		base=1,t=0;
		while(base*2<a[i]){
			base*=2;
			t++;
		}
		while(base>0){
			if( (a[i] & base) != 0)cnt[t].push_back(i);
			base/=2;
			t--;
		}
	}
	solve();
	return 0;
}
