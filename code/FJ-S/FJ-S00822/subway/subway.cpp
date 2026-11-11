#include<bits/stdc++.h>

using namespace std;
int w[405],k[205];
int a[205][205];
int t[205][205];
struct node{
	int r,z;
}b[205];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int ans=0,f,g;
		cin>>b[i].r>>b[i].z;
		ans+=w[b[i].r];
		ans+=w[b[i].z];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=2*k[i];j++){
				if(a[i][j]>=b[i].r&&a[i][j]<=b[i].z){
					ans+=t[i][j];
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
