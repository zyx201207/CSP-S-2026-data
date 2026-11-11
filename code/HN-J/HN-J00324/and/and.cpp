#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0,maxn;
	int a[100005]= {};
	cin>>n>>m;
	for(int i=1; i<=n; i++) 
		cin>>a[i];
		for(int i=1; i<=n; i++) {
			maxn=a[i]&a[i+1];
			if(maxn>ans) {
				ans=maxn;
				maxn=0;
			}
		}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
