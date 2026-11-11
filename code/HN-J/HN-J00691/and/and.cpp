#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i;
	cin>>n>>m;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==n){
		long long s=a[0];
		for(i=1;i<n;i++){
			s=s&a[i];
		}
		cout<<s;
	}else{
		sort(a,a+n);
		cout<<a[n-1];
	}
	return 0;
}
