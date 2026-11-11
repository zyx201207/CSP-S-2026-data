#include <bits/stdc++.h>
using namespace std;

long long c,t,n,d;
int a[2000005],ch[2000005],zh[2000005],z[2005];

void dfs(int ix,int h){
	
	if(h<zh[ix]){
		zh[ix]=h;
		ch[ix]=1;
	}else if(h==zh[ix]){
		ch[ix]++;
			
	}
	if(ix==n) return;
	
	
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
		cin>>n>>d;
		for(int j=1;j<=n;j++) cin>>a[j];
		
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++) zh[k]=99999;
			for(int k=1;k<=n;k++) ch[k]=0;
			dfs(j,0);
			for(int k=1;k<=n;k++){
				if(ch[k]==2) z[i]++;
				
			}
		}
		
	}
	
	for(int i=1;i<=t;i++) {
		cout<<z[i]<<endl;
	}
	
	
	return 0;
}
