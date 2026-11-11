#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long m;
	int a[100000005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int p,q;
	p=0;
	q=0;
	int ans[10005];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			p=a[n-i-1]-a[n-j-i-2];
			q+=p;
		}
		if(q<=m){
			ans[i]=i+1;	
			cout<<ans[0];	
		}
	}
	return 0;
} 
