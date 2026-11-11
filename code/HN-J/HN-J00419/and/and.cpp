#include<bits/stdc++.h>
using namespace std;
const int mu=200004;
int n,m,now,ans;
int g[200005],c;
bool b[200005];
int printff(){
	int ans=0,kfc=0;
	for(int k=1;k<=n;k++){
		if(b[k]==false) continue;
		if(kfc==0) ans=g[k];
		ans&=g[k],kfc++;
	}
	if(kfc==m) return ans;
	else return 0;
}
bool how(int x,int p){
	return x&int(pow(2,p));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	now=n;
	for(int i=1;i<=n;i++){
		cin>>g[i];b[i]=true;
	}
	
	for(int i=31;i>=0;i--){
		int f=0,ysf=0;
		if(now>=m) for(int j=1;j<=n;j++) f+=(how(g[j],i));

		if(f>=m && now>=m)
			for(int k=1;k<=n;k++)
				if(how(g[k],i)==0 && b[k]) b[k]=false,now--;
			
		if(now==m) ans=max(ans,printff());
	}
	cout<<ans;
	return 0;
}
