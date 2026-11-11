#include <iostream>
#include <algorithm>
using namespace std;
void js(){
	ios::sync_with_stdio(0);
	cin.tie(0);
}
const int N=2e5+10;
int a[N],n,m;
bool cmp(int q,int p){
	if(q!=p) return q>p;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	js();
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	long long sum=a[1];
	for(int i=2;i<=m;i++) sum=(sum&a[i]);
	cout<<sum;
	return 0;
}
