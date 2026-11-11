#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m-1;j++){
			b[i]=a[i]^a[j];
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum=max(b[i],b[i-1]);
	}
	cout<<sum;
	return 0;
}
