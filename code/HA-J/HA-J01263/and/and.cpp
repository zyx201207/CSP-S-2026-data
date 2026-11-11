#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
long long a[200005];
bool f(long long x, long long y) {
	return x>y;
}
long long serch(long long wns, int i) {
	if(!m||i==n){
		return wns;
	}
	if(wns&a[i]){
		m--;
		return serch(wns&a[i],i+1);
	}
	else{
		return serch(a[i],i+1);
	}
}
int main(int argc, char** argv) {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,f);
	m--;
	ans=serch(a[0],1);
	cout<<(m?0:ans);
	return 0;
}
