#include<bits/stdc++.h>
using namespace std;
long long w[500005],b[500][50],t[500][50];//w步行时间 b编号 
long long c,n,m,d,q,x;//n线路数 m站数 d被经过max q计划数
int f(long long st,long long en,long long lin){
	long long a,ein=9999999999;
	if(st==en)return 0;
	int nlin,nk;

	for(int k=0;b[lin][k]!=0;k++){

		nlin=0;nk=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=x;j++){
				if(i==lin)continue;
				if(b[i][j]==k)nlin=i;nk=j;
			}
		}	
		if(b[lin][k]==st && nlin){
			ein=min(ein,t[lin][k]+t[nlin][nk]+f(b[nlin][nk],en,nlin));
		}
	}
	cout<<endl;
	return ein;
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++)cin>>b[i][j]>>t[i][j];
	} 
	
	int st,en;
	for(int i=0;i<q;i++){
	
		cin>>st>>en;
		int e=999999999;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=x;j++){
				if(b[i][j]==st)e=min(e,f(st,en,i));
			}
		}
		cout<<e;
	}	
	
	
	
	return 0;
}
