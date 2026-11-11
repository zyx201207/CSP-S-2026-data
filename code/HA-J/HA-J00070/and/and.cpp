#include <bits/stdc++.h>
using namespace std;
long long a[200005],n,m,ans;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	ans=a[0];
	for(int i=1;i<m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
