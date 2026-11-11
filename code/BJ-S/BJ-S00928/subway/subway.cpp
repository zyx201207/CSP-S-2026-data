#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,shi,zhan,s[500005],b[500005][3][3],k,x,y,sum,zha,sh,u,v;
bool o[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		cin>>zhan>>shi;
		cin>>zha>>sh;
		b[zhan][1][1]=shi;
		b[zhan][2][1]=zha;
		b[zha][1][2]=sh;
		b[zha][2][2]=zhan;		
		k=0;
	}
	for(int i=1;i<=p;i++){
		sum=0;
		cin>>x>>y;
		if(b[b[x][2][1]][2][1]==x){
			o[b[b[x][2][1]][2][2]]=1;
		}else{
			o[b[b[x][2][1]][2][1]]=1;
		}
		while(x!=y){
			cout<<"*";
			if(o[b[x][1][1]!=1]){
				u=b[x][1][1];
				v=b[x][2][1];
			}else{
				u=b[x][1][2];
				v=b[x][2][2];
			}
			sum=sum+s[x]+u;
			x=v;
		}
		//sum=sum+s[x]+b[x][1];
		o[b[x][1][1]]=1;
		o[b[x][1][2]]=1;
		cout<<sum<<endl;
	}
	return 0;
}
