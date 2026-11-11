#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	int n,m,g;
	cin>>n>>m;
	vector<int>a(n+1);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	for(int i=0;i<m-2;i++){
		g=max(a[i]&a[i+1],a[i+1]^a[i+2]);
	}
	cout<<g<<endl;
	return 0;
}
