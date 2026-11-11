#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const long long inf=1e13;
const int N=2e5+10;
int a[N];
int n,m,maxn;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int> ans,b;
	for(int i=1;i<=n;i++) cin>>a[i],b.push_back(a[i]),maxn=max(maxn,a[i]);
	for(int i=20;i>=0;i--){
		int cnt=0;
		ans.clear();
		for(int bi : b)
			if(bi&(1<<i)) cnt++,ans.push_back(bi);
		if(ans.size()>=m) b=ans;
	}int ansl=b[0];
	for(int bi : b) ansl&=bi;
	cout<<ansl;
	return 0;
}

