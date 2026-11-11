#include<bits/stdc++.h>
using namespace std;
int n,m,x,iop[200005],asd;
bool e[32],g[32],h[32];
int zxc[200005];
int f(int a,int b){
	int qwe=0,ans=0;
	while(a>0){
		qwe++;
		e[qwe]=a%2;
		a/=2;
	}
	int asd=0;
	while(b>0){
		asd++;
		g[asd]=b%2;
		b/=2;
	}
	for(int i=1;i<=max(asd,qwe);i++){
		if(e[i]==1&&g[i]==1) h[i]=1;
		else h[i]=0;
	}
	for(int i=1;i<=31;i++){
		ans+=h[i]*pow(2,i-1);
	}
	return ans;
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>iop[i];
	}
	sort(iop+1,iop+n+1);
	int j=1;
	for(int i=n;i>=n-m+1;i--){
		zxc[j]=iop[i];
		j++;
	}
	for(int i=1;i<=m;i++){
		zxc[i+1]=f(zxc[i],zxc[i+1]);
	}cout<<zxc[m];
return 0;}

