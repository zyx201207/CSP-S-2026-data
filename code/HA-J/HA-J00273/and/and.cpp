#include<bits/stdc++.h>
using namespace std;
int a[350000][50];
int q[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[n+1];
	for(int i=1;i<=n;i++){
		cin>>b[i];
		int u=b[i];
		int j=1;
		while(u!=0){
			int y=u%2;
			a[i][j]=y;
			u/=2;
			j++;
		}
		a[i][j]=2;
	}
	for(int i=1;i<=n;i++){
		int w[50],ws=-1;
		bool o=0;
		for(int j=30;j>0;j--){
			if(a[i][j]==2){
				o=1;
			}
			if(o==1){
				ws++;
				w[j]=a[i][j];
			}
		}
		for(int j=1;j<=ws;j++){
			a[i][ws-j+1]=w[j];
		}
	}
	for(int i=1;i<=n;i++){
		int o=0,p=1;
		for(int j=31;j>0;j--){
			if(a[i][j]==2){
				o=1;
				continue;
			}
			if(o==1){
				if(a[i][j]==1){
					q[p]++;
				}
				p++;
			}
		}
	}
/*	for(int i=1;i<=n;i++){
		cout<<endl;
		for(int j=1;j<20;j++){
			cout<<a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		cout<<q[i]<<' ';
	}*/
	int zg;
	for(int i=33;i>0;i--){
		if(q[i]>=m){
			zg=i;
			break;
		}
	}
	int cx[350000];
	int e=1;
	for(int i=1;i<=n;i++){
		if(a[i][zg]==1){	
			cx[e]=i;
			e++;
		}
	}
	cx[e]=-1;
	int jc=1;
	bool oo=0;
	if(e-1==m){
		
	}
	else
	while(0==1){
		int x=1;
		for(int i=1;i<=n;i++){
			if(cx[x]==-1){
				break;
			}
			int o=0,p=1;
			if(cx[x]!=i){
				continue;
			}
			x++;
			for(int j=31;j>0;j--){
				if(a[i][j]==2){
				o=1;
				continue;
				}
				if(o==1){
					if(a[i][j]==1){
						q[p]++;
					}
				p++;
				}
			}
		}
		
		int jcc=jc;
		if(e-1==m){
			break;
		}
		int zg=-1;
		for(int i=33;i>0;i--){
			if(q[i]>=m){
				if(jcc!=0){
					jcc--;
					continue;
				}
				zg=i;
				break;
			}
		}
		if(zg==-1){
			oo=1;
		}
		e=1;
		for(int i=1;i<=n;i++){
			if(a[i][zg]==1||oo==1){
				cx[e]=i;
				e++;
			}
		}
		cx[e]=-1;
		if(e-1==m||oo==1){
			break;
		}
		if(e<m){
			jc--;
			jc--;
			oo=1;
		}
		jc++;
	}
	/*for(int i=1;i<=4;i++){
		cout<<cx[i]<<' ';
	}*/
	int ans=-1,x=1;
	for(int i=1;i<=n;i++){
			if(cx[x]==-1){
				break;
			}
			if(cx[x]!=i){
				continue;
			}
			if(ans=-1){
				ans=b[cx[x]];
				
			}
			else{
				ans=ans&b[cx[x]];
			}
			x++;
	}
	cout<<ans;
	return 0;
}
