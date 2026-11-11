#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	
	long long a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	long long sum=a[1];
	for(int i=1;i<=m;i++){
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
