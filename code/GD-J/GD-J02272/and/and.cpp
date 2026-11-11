#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++)
		if(a[j]>a[j+1])swap(a[j],a[j+1]);
	}
//	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	cout<<a[n-m];
	return 0;
} 
