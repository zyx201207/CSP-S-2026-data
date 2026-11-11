#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,a[50005],t[50005];
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,sum=0;
		cin>>x>>y;
		for(int j=x;j<=y;j++)sum+=w[j];
		cout<<sum<<endl;
	}
	return 0;
}
