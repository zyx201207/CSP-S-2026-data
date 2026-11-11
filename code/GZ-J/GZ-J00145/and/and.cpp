//GZ-J00145 贾景栎 遵义市第四中学
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[10010],b[10010],k=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			b[k]=a[i]&a[j];
			k++;
		}
	}
	int maxx=-1;
	for(int i=1;i<=k;i++){
		if(b[i]>b[i+1])maxx=b[i];
	}
	cout<<maxx;
	return 0;
}

