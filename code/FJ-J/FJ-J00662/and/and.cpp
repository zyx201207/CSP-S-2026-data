#include<bits/stdc++.h>
using namespace std;
long long a[100003];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	queue<long long> q;
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	for(int i=0;i<m-1;i++){
		ans+=(a[i]&a[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}
