#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n>>m;
	int a[n+10];
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	}
	int ans=INT_MIN;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			ans=max(a[i]&a[j],ans);
		}
	}
	cout <<ans;
} 
