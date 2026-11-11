#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	unsigned long long a[200005]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n);
	unsigned long long ans=a[n-1];
	for(int i=n-2;i>n-1-m;i--){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
} 
