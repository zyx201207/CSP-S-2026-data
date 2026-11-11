#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]>=a[i-1]){
				ans++;
			}
		}
	}
	cout<<ans;
	
	
	
	return 0;
}
