#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[505];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int a[505][5];
	for(int i=1;i<=q;i++){
		int t;
		cin>>t;
		int b[505][3];
		for(int i=1;i<=t;i++){
			cin>>b[i][1]>>b[i][2];
		}
		for(int i=1;i<t;i++){
			a[i][1]=b[i][1];a[i][2]=b[i+1][1];a[i][3]=b[i][2];
		}
		a[t][1]=b[t][1];a[t][2]=0;a[t][3]=b[t][2];
	}
	int ans=0;
	while(q--){
		int x,y;
		cin>>x>>y;
		int mid=x;
		ans+=w[mid];
		while(mid==y){
			ans+=a[mid][3];	
			mid=a[mid][2];
					
		}
		ans+=w[y];
		cout<<ans;
	}

	return 0;
} 
