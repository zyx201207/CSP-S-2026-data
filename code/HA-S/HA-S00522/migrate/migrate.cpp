#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
freopen("migrate".in);
int n,m;
int f[N];
int sum=0;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	sort(f+1,f+n+1);
	for(int i=1;i<=m;i++){
		int x,y=0;
		int tep=999;
			for(int j=1;j<n;j++){
				if(f[j+1]-f[j]<tep){
					x=j;
					y=j+1;
				} 
				tep=min(tep,f[j+1]-f[j]);
			}
			
	}
	
	return 0;
	freopen("migrate".out);
} 
