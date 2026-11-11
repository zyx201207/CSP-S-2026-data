#include<bits/stdc++.h>
using namespace std;
int n,m,a[200020],b[35],A=1,B=0,BB,cccc[35],ans,maxxx=-1,hy[30][30][30];
void dfs(int x,int y){
	if(x==1){
		maxxx=a[y];
	}
	if(x==m){
		ans=max(ans,maxxx);
	}
	else{
		for(int i=y+1;i+m-x<=n;i++){
			hy[x][y][i]=maxxx;
			maxxx=maxxx&a[i];
			dfs(x+1,i);
			maxxx=hy[x][y][i];
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long ccc=1;
	for(int i=1;i<=31;i++){
		cccc[i]=ccc;
		ccc*=2;
		if(ccc==n){
			B=1;
			BB=i;
		}
	}
	ccc=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ccc=1;
		if(A==1){
			while(cccc[ccc]<a[i]||cccc[ccc]==1&&a[i]==1){
				ccc++;
			}
			if(a[i]+1!=cccc[ccc]){
				A=0;
			}
			ccc=1;	
		}
		if(B==1){
			if(a[i]!=i-1){
				B=0;
			}
		}
		maxxx=max(maxxx,a[i]);
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
			if(ans==0) break;
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		maxxx=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxxx=max(a[i]&a[j],maxxx);
			}
		}
		cout<<maxxx;
		return 0;
	}
	if(m==1){
		cout<<maxxx;
		return 0;
	}
	if(A==1){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	if(B==1){
		sort(a+1,a+1+n);
		ans=a[n];
		for(int i=1;i<m;i++){
			ans=(ans&a[n-i]);
		}
		cout<<ans;
		return 0;
	}
	maxxx=-1;
	for(int i=1;i+m<=n;i++){
		dfs(1,i);//¸öÊý£¬i 
	}
	cout<<ans;
	return 0;
}
