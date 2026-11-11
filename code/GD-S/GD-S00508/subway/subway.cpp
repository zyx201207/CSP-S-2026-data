#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,t,id; 
int w[500010],a[510][500010];
long long ans;

bool iseuq(int x,int y){
	for(int i=1;i<=m;++i){
		if(a[i][x]!=0 && a[i][y]!=0){
			id=i;
			return true;
		}
	}
	return 0;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int x;
			cin>>x>>t;
			a[i][x]=t;
		}
	}
	for(int i=1;i<=q;++i){
		ans=0;
		int x,y;
		cin>>x>>y;
		bool flag=iseuq(x,y);
		ans+=w[x]+w[y]+a[id][x]+a[id][y];
		if(flag){
			cout<<ans;
		}
	}
	return 0;
}
