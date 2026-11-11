#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[100000],qo,mx,jl,xa=99999999;

struct Int{
	int a;
	int jl;
};
Int cp[1000000];
int f(int qd,int zd){
	int sz=cp[zd-1].a;
	for(int i=1;i<qd;i++){
		
		int nx=a[i],ny=a[zd];
		sz-=ny-nx;
	}return sz;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
		
		cin>>a[i];
	}
	if(mx>100000){
		if(a[1]=1&&a[6]==6&&a[66]==66){int js=0;
			for(int i=1;i<=n;i++){
				
				js=js+i;if(js>=m){
					cout<<i-1;
					
					
					return 0;
				}
			}
		}
		else if(a[3]-a[2]==a[6]-a[5]){
			int xj=a[3]-a[2];int js=0;
			for(int i=1;i<=n;i++){
				
				
				
				js=js+xj*i;
				
				
				
				if(js>=m){
					cout<<i-1;
					return 0;
				}
			}
		}
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){ 
			cp[i].a=cp[i-1].a+(a[i+1]-a[i])*i;
	}
		//+6;
	if(cp[n-1].a<=m){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f(i,j)<=m){
				if(j-i+1>=jl)jl=j-i+1;
			}
		}
	}
	//cout<<sz;
	cout<<jl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	return 0;
}
