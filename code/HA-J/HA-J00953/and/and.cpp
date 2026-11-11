#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[200005],ans,maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			ans=a[i];
		}
		maxx=max(a[i],maxx);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
return 0;
}

