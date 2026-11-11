#include<bits/stdc++.h>
using namespace std;
int a[10009][10009];
int t[10009][10009];
int k[10009];
int w[10009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a1,t1;
			cin>>a1>>t1;
			a[i][j]=a1;
			t[i][j]=t1;
		}
	}
	int ans=0;
	for(int kk=1;kk<=n;kk++){
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			ans=w[1]+w[n];
			for(int j=1;j<=k[kk]-1;j++){
				ans+=a[j][j+1];
			}
		}		
	}
	cout<<ans;
	return 0;
}
