#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int MXN=5e5+1,MXN1=3e5+1;
int n,m;
int a[MXN],ans[MXN1];
void solve(int d){
	map<int,int>mp;
	vector<int>vec;
	for(int i=d;i<=n;++i){
//		cout<<a[i]<<" ";
		if(mp[a[i]]!=0){
//			cout<<1;
			vec.erase(vec.begin()+mp[a[i]]-1,vec.end());
//			for(auto e:vec)cout<<e<<" ";
//			cout<<endl;
		}
		vec.push_back(a[i]);
		mp[a[i]]=vec.size();
	}
	for(int i=0;i<vec.size();++i){
//		cout<<vec[i]<<" ";
		ans[vec[i]]++;
	}
//	cout<<endl;
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
//	ans[m]=n;
	for(int i=1;i<=n;++i){
		solve(i);
	}
//	solve(1);
	for(int i=1;i<=m;++i)cout<<ans[i]<<" ";
	return 0;
}
