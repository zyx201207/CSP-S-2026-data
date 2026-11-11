#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[600000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<map<long long,long long>a(m+10);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long len=0,k[600000],l[600000],x,y;
		cin>>len;
		for(int j=1;j<=len;j++){
			cin>>x>>y;
			k[j]=x;
			l[j]=y;
		}
		for(int j=1;j<len;j++){
			a[k[j]][j+1]=min(l[j]+l[j+1],a[k[j]][j+1]);
		}
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		cout<<a[x][y]<<endl;
	}
	return 0;
} 
