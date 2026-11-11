#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int p=0;
	for(int k=31;k>=0;k--){
		int f=p+(1<<k);
		int g=0;
		for(int j=1;j<=n;j++){
			if((a[j]&f)==f) g++;
		}
		if(g>=m) p=f;
	}
	cout<<p;
	return 0;
}
