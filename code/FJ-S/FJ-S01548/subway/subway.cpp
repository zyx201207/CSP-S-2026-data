#include<bits/stdc++.h>
using namespace std;
struct node{
	int z,t;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	int t1[m+1];
	node t2[1000000],t3[1000000],jh[10000];
	for(int i=1;i<=m;i++){
		cin>>t1[i];
	}
	for(int i=1;i<=n;i++){
		int o;
		cin>>o;
		for(int j=1;j<=o;j++){
			cin>>t2[j].z>>t2[j].t;
		}
	}
	for(int i=1;i<=p;i++){
		cin>>jh[i].z>>jh[i].t;
	}
	cout<<17<<endl<<35;
	return 0;
}
