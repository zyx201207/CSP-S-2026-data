#include <bits/stdc++.h> 
using namespace std;

long long a[200010]={},res,n;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int m,maxn=0,maxnp;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i] > maxn){
			maxn=a[i];
			maxnp=i;
		}
	}
	
	res = maxn;
	a[maxnp]=0;
	for(int i=1;i<=m-1;i++){
		int maxr=-1,maxp;
		for(int i=1;i<=n;i++){
			if(res&a[i] > maxr){
				maxr=res&a[i];
				maxp=i;
			}
		}
		res=maxr;
		a[maxp]=0;
	}
	cout << res;
	return 0;
}
