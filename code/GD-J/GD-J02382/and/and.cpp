#include <bits/stdc++.h>
using namespace std;
int b[200005],c[10000000],d[200005],t=1,n,m,ans,maxn,cnt=-1,cuc=0,xf=1;
void fix_c(int t,int n,int m){
	for(int i =t;i<=n-m+t;i++){
		if(cuc<m-1){
			cuc++;
			d[cuc]=b[i];
			cuc++;
			fix_c(cuc+i,n,m);
		}
		else{
			d[cuc]=b[i];
			ans=d[0];
			for(int j = 1;j<m;j++){
				ans=(ans&d[j]);
			}
			c[cnt]=ans;
			cnt++;
		}
	}
	cuc--;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	for(int i =0;i<n;i++){
		cin >> b[i];
	}
	ans=b[0];
	d[0]=b[0];
	for(int i =1;i<=n;i++){
		xf*=i;
	}
	for(int i =1;i<=m;i++){
		xf/=m;
	}
	if(m==1){
		for(int i =0;i<n-1;i++){
			maxn=max({maxn,b[i],b[i+1]});
		}
		if(n>1) cout<<maxn;
		else cout<<b[0];
	}
	else if(m==n){
		for(int i =0;i<n-1;i++){
			ans=(ans & b[i+1]);
		}
		cout<<ans;			
	}
	else{
		fix_c(0,n,m);
		for(int i =0;i<xf;i++){
			maxn=max(c[i],c[i+1]);
		}
		if(n>1) cout<<maxn;
		else cout<<b[0];
	}
	return 0;
}
