#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int tu[500010];
	int id[500010];
}a[510];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int td[500010]={};

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>td[i];
	}for(int k,i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i].id[j]>>a[i].tu[j];
		}
	}
	for(long long x,y,i=1;i<=q;i++){
		cin>>x>>y;
		while(x--){
			if(y%2)y=y*5-1;
			else y=y/2+1; 
		}cout<<y<<"\n";
	}
	return 0;
} 
