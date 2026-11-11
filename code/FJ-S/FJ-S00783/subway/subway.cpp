#include<bits/stdc++.h>
using namespace std;
queue<int>q[500005][2];
int n,m,c,d,p,a[1000005],w[1000005],k,o[100005],v[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		cin>>o[1]>>v[1];
		for(int j=2;j<=k;j++){
			cin>>o[i]>>v[i];
			q[o[1]][0].push(o[i]);
			q[o[1]][1].push(v[i]);
		}
	}
	int l,r;
	for(int i=1;i<=p;i++){
		cin>>l>>r;
		while(l!=r){
			c+=q[l][1].front();
		    l=q[l][0].front();
			c+=q[l][1].front();
		}
		cout<<c<<endl;
	}
	return 0;
} 
