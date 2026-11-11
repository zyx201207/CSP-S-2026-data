#include<bits/stdc++.h>
using namespace std; 
long long lz,k,d[35],q,vis[20005],ans;
long long a[20005];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(lz<a[i])lz=a[i];
	}
	while(lz){
		lz/=2;
		k++;
	}	
	k--;
	d[k+1]=1;
	for(int i=k;i>=1;i--){
		d[i]=d[i+1]*2;
	}
	for(int i=1;i<=k;i++){
		int num=0;
		for(int j=1;j<=n;j++){
			if(a[j]>d[i]&&(vis[j]==1||q==0)){
				num++;
				vis[j]=1;
			}
		}
		if(num>=m){
			ans+=d[i];
			q=1;
		}else{
			if(q==0)for(int h=1;h<=n;h++)vis[h]=0;
		}
	}
	cout<<ans;
	return 0;
} 
