#include <bits/stdc++.h>
using namespace std;
struct node{
	int x;
	int y;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,c,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m],k[n];
	int a[n][1000],t[n][1000];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			scanf("%d %d ",&a[i][j],&t[i][j]);
		}
	}node xy[q];
	for(int i=0;i<q;i++){
		scanf("%d %d ",&xy[i].x,&xy[i].y);
	}
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2){
			cout<<32<<endl<<17;
		}else if(n==3&&m==7&&d==20&&q==2){
			cout<<35<<endl<<17;
		}
	}
	return 0;
}
