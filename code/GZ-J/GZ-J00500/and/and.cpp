//GZ-J00500 遵义市第十二中学 梅东耀 
#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+4;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=-1e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n-m;i++){
		int ans=a[i];
		for(int j=1;j<m;j++){
			ans&=a[i+j];
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}
