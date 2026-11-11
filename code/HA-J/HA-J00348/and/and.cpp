#include <bits/stdc++.h>
using namespace std;
int n,m,c[200005],qs=0,sf=0,q1=0,q2=0,ans=1,zda=0,zsf=0;
int log2(int a){
	qs=0;
	sf=0;
	while(a>=2){
		if(a%2==1){
			sf=1;
		}
		qs++;
		a/=2;
	}
		return qs+1;
}
int yh(int a,int b){
	return  a^b^((1<<(log2(max(a,b))))-1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==2){
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
//				cout<<yh(i,j)<<" "<<log2(max(i,j))<<" "<<i<<" "<<j<<" "<<endl;
				zsf=max(zsf,yh(c[i],c[j]));
			}
		}
		cout<<zsf;
	}
	else if(m==n){
		cin>>c[1];
		ans=c[1];
		for(int i=2;i<=n;i++){
			cin>>c[i];
			ans=yh(ans,c[i]);
		}
		cout<<ans;
	}
	else if(m==n-1){
		cin>>c[1];
		ans=c[1];
		for(int i=2;i<=n;i++){
			cin>>c[i];
			ans=yh(ans,c[i]);
		}
		for(int i=1;i<=n;i++){
			zda=max(zda,yh(ans,c[i]));
			
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>c[i];
			zsf=max(zsf,c[i]);
		}
		cout<<zsf;
	}
}
