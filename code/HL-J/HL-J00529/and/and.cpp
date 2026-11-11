#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[200001];
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	if(m==1){
		long long maxi=-1;
		for(int i=1; i<=n; i++)maxi=max(maxi,a[i]);
		cout<<maxi;
		return 0;
	}
	cout<<0;
	return 0;
}