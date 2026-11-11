#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,a[222222],b[555555],t=0,ans=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			b[t]=a[i]^a[j];
			t++;
		}
	}
	for(int i=1;i<t;i++){
		ans=max(b[i],b[i-1]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
