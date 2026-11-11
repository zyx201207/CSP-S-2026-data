#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=1;j<=m;j++){
			if(a[j]!=a[j++]){
				a[j]++;
			}
			else{
				sum++;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;

	return 0;
} 
