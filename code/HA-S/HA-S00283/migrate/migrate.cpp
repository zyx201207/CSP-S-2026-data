#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n[N],d[N],x[2000005][N],y[N][N]={0};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,o=1,num=0,sum=0;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++){
			cin>>x[j][i];
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n[i];j++){
			for(int h=o;h<=n[i];h++){
				if(x[j][i]-x[h][i]<0){
					if(x[h][i]-x[j][i]<=d[i]){
						y[j][h]=x[h][i]-x[j][i];
						y[h][j]=y[j][h];
					}		
				}else{
					if(x[j][i]-x[h][i]<=d[i]){
						y[j][h]=x[j][i]-x[h][i];
						y[j][h]=y[h][j];
					}
				}
			}
			o++;
		}
		o=1;
		for(int j=1;j<=n[i];j++){
			for(int h=o;h<=n[i];h++){
				if(h-j==d[i]*2-1&&y[j][h]==0){
					num++;
				}
			}
			o++;
		}
		o=1;
		cout<<num+1<<endl;
		num=0;
		sum=0;
	}
	return 0;
}
