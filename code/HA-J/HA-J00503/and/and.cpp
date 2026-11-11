#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	string e[n];
	cin>>n>>m;
	int a[n+5];
	long long mn;
	string cnt[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<n-1;j++){
		mn=min(a[j],a[j+1]);
	}
	cout<<mn;

	return 0;
}
