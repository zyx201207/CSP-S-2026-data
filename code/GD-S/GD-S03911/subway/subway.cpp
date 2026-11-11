#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
map<int,int> ma;
int w[500005];
int a[505][500005];
int t[505][500005];
int l,r;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>a[i][j]>>t[a[i][j]][j];
			ma[a[i][j]]=t[a[i][j]][j];
		}
	}
	int ans=0;
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		ans+=w[l]+w[r];
		for(int j=l;j<=r;j++){
			ans+=ma[j];
		}
	}
	cout<<ans;
	return 0;
} 
