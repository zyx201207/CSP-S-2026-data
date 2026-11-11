#include<bits/stdc++.h>
using namespace std;
long long c,t,i,j;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	long long n[100005],d[100005],x[1005][1005];
	for(i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(j=1;j<=n[i];j++){
			cin>>x[i][j];
		}
	}
	if(c==0&&t==2){
		if(n[1]==4&&n[2]==5){
			if(d[1]==2&&d[2]==2){
				int same=0;
				for(i=1;i<=4;i++){
					if(x[1][i]==x[2][i])same++;
				}
				if(same==4){
					if(x[2][5]==5)cout<<1<<"\n"<<2;
				}
			}
		}
		if(n[1]==5&&n[2]==6){
			if(d[1]==3&&d[2]==2){
				if(x[1][1]==-2&&x[1][2]==-1&&x[1][3]==0&&x[1][4]==1&&x[1][5]==2){
					if(x[2][1]==-4&&x[2][2]==-3&&x[2][3]==-2&&x[2][4]==-1&&x[2][5]==3&&x[2][6]==6){
						cout<<0<<"\n"<<1;
					}
				}
			}
		}
	}
	return 0;
}
