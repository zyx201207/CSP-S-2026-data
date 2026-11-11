#include<bits/stdc++.h>
using namespace std;
int a[10008];
int b[10008][10008];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			b[i][j]=a[i]-a[j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=1;j<=i;j++){
			s+=b[i][j];
		}
		if(s<=m&&i>=ans){
			ans=i;
		}
	}
	cout<<ans;
	
	return 0;
}
