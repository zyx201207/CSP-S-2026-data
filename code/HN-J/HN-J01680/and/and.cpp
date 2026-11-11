#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200001],ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,(a[i]&a[j]));
		}
	}
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
