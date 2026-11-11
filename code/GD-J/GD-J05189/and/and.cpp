#include<bits/stdc++.h>
using namespace std;
int d[210000];
int f[210000];
int c[210000];
int n,m;
int maxx=-1;
void dfs(int x){
	if(x>m){
		int p=d[1];
		for(int i=2;i<=m;i++){
			p=p&d[i];
		}
		maxx=max(p,maxx);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(f[i]!=1){
			//cout<<i<<" ";
			d[x]=c[i];
			f[i]=1;
			dfs(x+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//int a[5][5];
	//a[1][1]=1;a[1][2]=0;a[1][3]=1;a[1][4]=0;	
	//a[2][1]=0;a[2][2]=2;a[2][3]=2;a[2][4]=0;
	//a[3][1]=1;a[3][2]=2;a[3][3]=3;a[3][4]=0;
	//a[4][1]=0;a[4][2]=0;a[4][3]=0;a[4][4]=4;

	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1){
		sort(c+1,c+1+n);
		cout<<c[n];
	}
	else if(m==2){
		//int b[2100][2100];
		int ma=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int p=c[i]%c[j];
				ma=max(p,ma);
			}
		}
		cout<<ma;
	}
	else if(m==n){
		int p=c[1];
		for(int i=2;i<=n;i++){
			p=p&c[i];
		}
		cout<<p;
	}
	else if(m==n-1){
		int mx=-1;
		for(int i=1;i<=n;i++){
			int p=2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2-1;
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				p=p&c[j];
			}
			mx=max(mx,p);
		}
		cout<<mx;
	}
	else{
		dfs(1);
		cout<<maxx;
	}
	
	
	
	return 0;
} 
