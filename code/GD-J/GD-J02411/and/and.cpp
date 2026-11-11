#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	cout<<a[n-m];
	return 0;
}
