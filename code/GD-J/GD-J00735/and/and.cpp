#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);	
	freopen("and.out","w",stdout);
	
	long long n,m,a[200005],maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long ans=a[i],b=i;
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=m;k++){
				ans&=a[++b];
			}
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

