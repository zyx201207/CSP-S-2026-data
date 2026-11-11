//GZ-J00510 金浩 兴义市弘毅中学 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 ll n,m,a[200005],maxp=-1,maxb=-1;
 ll b[2000005];
 bool f[8000000];
 void dfs(ll step){
 	if(step==m+1){
 		ll g=b[1];
 		for(int i=2;i<=m;i++){
 			g=g&b[i];
 		//	cout<<b[i]<<" ";
		 }
 		maxb=max(maxb,g);
 	memset(f,0,sizeof(f));
 		return;
	 }
 	for(int i=1;i<=n;i++){
 		if(f[a[i]]==0){
 			 b[step]=a[i]; 
 			 f[a[i]]=1;
		 }
	else continue;
	 dfs(step+1);
	 } 

 }
 
 
int main(){
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
 ios::sync_with_stdio(false);	
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		maxp=max(maxp,a[i]);
	} 
	
	
	if(m==1){
		cout<<maxp;
		return 0;
	}
	if(m==2){
		maxp=-9;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++){
				maxp=max(maxp,(a[i]&a[j]));
			//	cout<<(a[i]&a[j])<<" ";
				//cout<<maxp;
			}
		}
		cout<<maxp;
		return 0;
	}
	if(m==n){
		maxp=a[1];
		for(int i=2;i<=n;i++){
			maxp=maxp&a[i];
		}
		cout<<maxp;
		return 0;
	}
if(m==n-1){

	ll  t;
	ll maxn=-1;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
		if(i!=j&&i==j+1){
			t=a[i];
		}
			if(i!=j&&i==1){
				t=a[i];
			}
			if(i!=j&&i!=j+1){
				t=t&a[i];
		}
		
		
	}
	maxn=max(maxn,t);
	}
	cout<<maxn;
	return 0;
	
} 


	dfs(1);
	cout<<maxb;
	
	
	return 0;
} 
