#include<bits/stdc++.h> 
using namespace std;
int main(){
	int a[200005];
	int cnt=0;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<n*(n-1);j++) {
		int cnt1=0;
		for(int k=0;k<m;k++)
			cnt1=a[j+k]&a[j+k+1];
		if(cnt1>cnt)
			cnt=cnt1;
	}
	cout<<cnt;
	return 0;
}
