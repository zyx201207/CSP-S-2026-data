//GZ-J00370 贵阳市第十八中学 曹语心
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+500;
int a[N],n,m,maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1) cout<<maxn;
	return 0;
} 
