#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[999999],vis[999999],stepmin,kk,k;
int df(int x,int ll,int step){
	if(step>stepmin)return 0;
	if(x==ll){
	kk++;	
	return 0;
	}
	for(int ii=d;ii>=ll%d;ii--){
		df(x+ii,ll,step+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		k=0;kk=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		if(d>=(a[n]-a[1])){
			cout<<0<<endl;
			continue;
		}
		for(int nn=d+2;nn<=n;nn++){
		if(nn%d==0)stepmin=nn/d;
		else stepmin=nn/d+1;
		df(1,nn,0);
		if(kk==2)k++;	
		}
		cout<<k<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
