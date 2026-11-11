#include <bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n,m,a[N],maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j) maxn=max(maxn,a[i]&a[j]);
	}cout<<maxn;
	return 0;
}
