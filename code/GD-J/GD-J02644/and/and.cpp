#include<bits/stdc++.h>
using namespace std;
using B = bitset<32>;
vector<B> a;
bool cmp(B a,B b){
	return a.to_ulong()>b.to_ulong();
}
int main() {
	freopen("and5.in","r",stdin);
	freopen("222.out","w",stdout); 
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	long n,m;
	cin>>n>>m;
	if(m==1) {
		int m=-1,b;
		while(cin>>b) m=max(b,m);
		cout<<m;
		return 0;
	}
	if(m==n){
		int b;
		cin>>b;
		int ans=b;
		while(cin>>b) ans&=b;
		cout<<ans;
		return 0;
	}
	a.resize(n+1);
	for(int g=0;g<n;++g){
		long bb;
		cin>>bb;
		a.push_back(bb);
	}
	for(int w=31;w>=0;--w){
		vector<B> now;
		int on=0;
		for(auto f:a) 
			if(f[w]==1){
				on++;
				now.push_back(f);
			}
		if(on>=m) a=now;
	}
	sort(a.begin(),a.end(),cmp);
	long ans=a[0].to_ulong();
	for(int g=1;g<m;++g)
		ans&=a[g].to_ulong();
	cout<<ans;
	return 0;
} 
