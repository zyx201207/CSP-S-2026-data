#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w"stdout);
	int n,m;
	cin>>n>>m;
	long long a[222222];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	long long b[m+1];
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int l=i+1;l<=n;l++){
			int v=1;
			b[v]=a[i];
			for(int j=l;j<l+m-1;j++){
				v++;
				b[v]=a[j];
			}
			int sum=b[1];
			for(int k=2;k<=m;k++){
				sum and b[k];
			}
			if(ans<sum){
				ans=sum;
			}
		}
	}
	cout<<ans;
	return 0;
}
