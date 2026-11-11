#include <bits/stdc++.h>
using namespace std;
long long t[100][100020],w[100020],a[100][100020];
int c,n,m,d,q,k1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){cin >>w[i];}
	for(int i=1;i<=n;i++){
		cin >>k1;
		for(int j=1;j<=k1;j++){
			cin >>a[i][j]>>t[i][j];
		}
	}
	int mu[100],mb[100];
	for(int i=1;i<=n;i++){
		cin >>mu[i]>>mb[i];
	}
	int yx,xy; 
	int sum=0;
	int l;
	for(int i=1;i<=n;i++){
		sum=0;l=i;
		yx=mu[i],xy=mb[i];
		sum+=w[yx];
		for(int j=yx;j<=xy;j++){
			if(t[l][j]!=0){
				sum+=t[l][j];continue;
			}
			while((++l&&t[l][j]==0)&&l<=n){}
			if(t[l][j]!=0){
				sum+=t[l][j];
			}
			while((--l&&t[l][j]==0)&&l>=1){}
				if(t[l][j]!=0){
					sum+=t[l][j];
				}
		}
		sum+=w[xy];cout <<sum<<endl;
	}
	return 0;
}
