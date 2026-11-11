#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travle.in","w",stdin);
	freopen("travel.out","r",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	cin>>a[0];
	int sum=a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<m;i++){
		sum=a[i]&sum;
	}
	cout<<sum;
	return 0;
}
