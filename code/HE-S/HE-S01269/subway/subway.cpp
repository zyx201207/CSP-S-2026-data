#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,p,k,l,u;
int w[500005];
int t[1000005];
int a[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>t[j];
		}
		for(int j=1;j<=2*k;j+=2){
				a[(j+1)/2]=t[j+1];
		}
	}
	for(int i=0;i<p;i++){
		cin>>l>>u;
		if(n==1){
			cout<<w[l]+w[u]+a[l]+a[u];
		}
	}
	return 0;
}
