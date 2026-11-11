//GZ-S00173 贵阳市新世界学校 李铭赫 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int w[N],a[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		a[i]=INT_MAX;
	}
	a[1]=0;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		while(k--){
			int j,t,xl; cin>>j>>t;
			if(i==j) xl=a[i]+t;
			a[j]=min(a[j],xl+t);
		}
	}
	while(q--){
		int x,y; cin>>x>>y;
		cout<<a[y]<<" "<<a[x]<<" "<<a[y]-a[x]+w[x]+w[y]<<endl;
	}
	return 0;
}
