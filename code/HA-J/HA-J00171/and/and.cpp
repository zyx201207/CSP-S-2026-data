#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m;
long long ans;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
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
