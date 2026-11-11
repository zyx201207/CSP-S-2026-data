#include <bits/stdc++.h>
using namespace std;

long long c,t,n,k;
int a[2000005],b[2000005],z[2005];

void dfs(int ix,int iy,int h){
	
	if(h<zh[ix]){
		zh[ix]=h;
		ch[ix]=1;
	}else if(h==zh[ix]){
		ch[ix]++;
			
	}
	if(ix==iy) return;
	
	
	for(int i=1;ix+i<=n;i++){
		if(a[ix+i]-a[ix]<=d){
			dfs(ix+i,h+1);
			
		}
	}

	
	return;
}


int main() {
	
	cin>>c>>t;
	for(int j=0;j<=t;j++) z[j]=0;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<n;j++) cin>>a[j]>>b[j];
		
		for(int j=1;j<=n;j++){
			for(int p=j+1;p<=n;p++){
				dfs(j,p,0)
			}
		}
		
	
		
	}
	
	for(int i=1;i<=t;i++) {
		cout<<z[i]<<endl;
	}
	
	
	return 0;
}
