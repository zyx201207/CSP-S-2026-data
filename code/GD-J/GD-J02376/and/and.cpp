#include <bits/stdc++.h>
using namespace std;
int n,m;
int g[200020];int y=2;int ans;
main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>g[i];
	}
	
	for(int i=1;i<n;i++){
		if(g[i]>g[0]) swap(g[0],g[i]);
		
	}
	if(m==1){
		cout<<g[0];return 0;
	}
	if(m==n){
		int sum=g[0];
		for(int i=1;i<n;i++){
			sum=sum&g[i];
		}
		cout<<sum;return 0;
	}
	int uu=0,o=0,oo=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if((g[i]&g[j])>uu){
				uu=g[i]&g[j];o=i;oo=j;
			}
		}
	}
	swap(g[0],g[o]);
	ans=uu;g[0]=0;g[oo]=0;
	while(y<m){
		int mx=0;int temp=0;
		for(int i=0;i<n;i++){
			if((ans&g[i])>mx){
			mx=ans&g[i];
			temp=i;
			}
		}
		g[temp]=0;
		ans=mx;
		y++;
		mx=0;
		if(ans==0) break;
	}
	cout<<ans;
	return 0;
} 
