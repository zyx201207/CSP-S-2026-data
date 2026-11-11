#include<bits/stdc++.h>
using namespace std;
int main(){
	int _;
	int n,m,q;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>_>>n>>m>>_>>q;
	
	int w[m+5]={0},k[n+5]={0},a[n+5][m+5]={0};
	
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int t1,t2;
			scanf("%d%d",&t1,&t2);
			a[i][t1]=t2;
		}
	}
	for(int i=1;i<=q;i++){
		int l,r,sum,x=1;
		cin>>l>>r;
		sum=w[l];
		for(int j=l;j<=r;j++){
			if(a[x][j]==0){
				x++;
				j--;
			}
			sum+=a[x][j];
		}
		cout<<sum+w[r]<<"\n";
	}
	return 0;
}

