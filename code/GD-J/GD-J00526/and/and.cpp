#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long maxx=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			long long b=a[i]&a[j];
			maxx=max(maxx,b);
		}
	}
	cout<<maxx;
	return 0;
}
