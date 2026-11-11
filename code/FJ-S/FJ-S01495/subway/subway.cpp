#include<bits/stdc++.h>
using namespace std;
int a[500005][500005][3],a1[500005][21],ad[500005],nt,lt=10000000;
/*int tA(int x,int y){
	if(x==y)return;
	for(int i=0;i<ad[x];i++){
		nt+=a1[x][20];
	}
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,x,y,t=0;
	//bool A=1;
	cin>>c>>n>>m>>d>>q;
	int w[m],k[n];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j][0]>>a[i][j][1];
		}
	}
	/*if(A){
		for(int y=0;y<n;y++){
			a1[a[y][0][0]][ad[a[y][0][0]]=a[y][1][0];
			ad[a[y][0][0]]++;
			a1[a[y][0][0]][20]=a[y][0][1];
		}
	}*/
	for(int i=0;i<q;i++){
		cin>>x>>y;
		t=0;
		if(n==1){
			t+=w[x]+w[y];
			for(int z=0;y<n;y++){
				for(int j=0;j<k[i];j++){
					if(a[z][j][0]==x){
						t+=a[i][j][1];
					}
					if(a[z][j][0]==y){
						t+=a[y][j][1];
					}
				}
			}
		}
		/*if(n==2){
			int u=1000000;
			t+=w[x]+w[y];
			for(int z=0;y<n;y++){
				for(int j=0;j<k[i];j++){
					if(a[z][j][0]==x){
						t+=a[z][j][1];
					}
					if(a[z][j][0]==y){
						t+=a[z][j][1];
					}
					a[z][j][2]+=1;
					if(a[z][j][2]==2&&a[0][j])
				}
			}
		}
		*/
	}
	cout<<t;
}
