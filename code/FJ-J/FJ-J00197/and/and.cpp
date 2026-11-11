#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a.begin(),a.end());
		cout<<a[n-1];
		return 0;
	}
	if(m==n){
		long long k=a[0];
		for(int i=1;i<n;i++){
			k=k&a[i];
		}
		cout<<k;
		return 0;
	}
	sort(a.begin(),a.end());
	cout<<a[n-1];
	return 0;
}
