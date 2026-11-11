#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(long long x,long long y){
	return x > y;
}
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1,a + n + 1,cmp);
	if(m == 1){
		cout<<a[1];
		return 0;
	}
	long long v = a[1];
	for(int i = 2;i <= m;i++){
		v = (v & a[i]);
	}
	cout<<v;
	return 0;
}
