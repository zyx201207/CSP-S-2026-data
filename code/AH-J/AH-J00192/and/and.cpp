#include<bits/stdc++.h>
using namespace std;
int n,m,a[214514],d[214514];
bool b[200001][31],c[214514];
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;for(int i=1;i<=n;i++){
		cin>>a[i];d[i]=a[i];
	}//sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int u=0;
		while(a[i]>0){
			if(a[i]%2==1)b[i][u]=1;
			a[i]>>=1;u++;
		}
	}
	//for(int i=1;i<=n;i++){
	//	for(int j=10;j>=0;j--)cout<<b[i][j];
	//	cout<<"\n";}
	for(int k=30;k>=0;k--){int y=0;
		for(int i=1;i<=n;i++){
			if(!c[i]&&b[i][k]){
				y++;
			}
		}//cout<<y<<endl;
		if(y>=m){
			for(int i=1;i<=n;i++){
				if(!c[i]&&!b[i][k]){
					c[i]=true;
		    	} 
			}
		}
	}int u=0,as=-1;
	for(int i=1;i<=n;i++){
		if(u==m)break;
		if(!c[i]){
			if(as==-1)as=d[i];
			else as&=d[i];
			u++;
			//cout<<as<<' ';
		}
	}cout<<as;
	return 0;
}
