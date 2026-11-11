#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,xi,xj,yi,yj;
int a[505][50009]={0},t[505][50009]={0};
void fin(int x){
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			if(a[i][j]==x){
				xi=i;
				xj=j;
				break;
			}
		}
	}
}
void fi(int y){
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			if(a[i][j]==y){
				yi=i;
				yj=j;
				return;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	int w[m+10]={0};
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		int x=0,y=0,sum=0;
		cin>>x>>y;
		fin(x);
		fi(y);
		if(xi==yi){
			sum=sum+w[x]+t[xi][xj]+t[yi][yj]+w[y];
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
