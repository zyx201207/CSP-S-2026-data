#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[200010];
int n,m,x,b,ans;
bool cmp(pair<int,int> aa,pair<int,int> bb){
	if(aa.second==bb.second)return aa.first>bb.first;
	return aa.second>bb.second;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].first;
		b=0;
		x=a[i].first;
		for(;x>=1;){
			if(x&1==1)b++;
			x=x>>1;
		}a[i].second=b;
	}sort(a+1,a+n+1,cmp);
	ans=a[1].first;
	for(int i=1;i<=m;i++){
		cout<<a[i].first<<' '<<a[i].second<<'\n';
		ans=ans & a[i].first;
	}cout<<ans;
	return 0;
}
