#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
vector<int> arr;
void solve(vector<int> &v,int b){
	if(b==-1) return;vector<int> v1,v2;
	sort(v.begin(),v.end(),[&](int x,int y){return (x>>b&1)<(y>>b&1);});
	for(auto x:v) (!(x>>b&1)?v1:v2).push_back(x);
	if(v2.size()<m) return solve(v,b-1);
	solve(v2,b-1),v.clear();
	for(auto x:v1) v.push_back(x);
	for(auto x:v2) v.push_back(x);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),arr.push_back(a[i]);
	solve(arr,30);int ans=(1<<30)-1;
	for(int i=n-1;i>=n-m;--i) ans&=arr[i];
	printf("%d",ans);
	return 0;
}
