#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool vis[200005];
int qz[200005],hz[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	bool f=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1){
			f=0;
		} 
		if(i>1){
			qz[i]=qz[i-1]&a[i];
		}
		else{
			qz[i]=a[i];
		}
	}
	hz[n]=a[n];
	for(int i=n-1;i>=1;i--){
		hz[i]=hz[i+1]&a[i];
	}
	if(n<=20){
		int x,j,cnt,ans;
		int maxl=0;
		for(int i=0;i<(1<<n);i++){
			x=i,j=0,cnt=0,ans=0;
			while(x){
				if(x&1){
					vis[++j]=1;
					ans=a[j];
					cnt++;
				}
				else{
					vis[++j]=0;
				}
				x>>=1;
			}
			if(cnt==m){
				for(int k=1;k<=n;k++){
					if(vis[k]==1){
						ans&=a[k];
					} 
				}
				maxl=max(maxl,ans);
			}
		}
		cout<<maxl;
	}
	else if(m==1){
		int maxl=0;
		for(int i=1;i<=n;i++){
			maxl=max(maxl,a[i]);
		}
		cout<<maxl;
	}
	else if(m==n){
		int ans=(1<<30)-1;
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans; 
	}
	else if(m==2){
		int maxl=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxl=max(maxl,(a[i]&a[j]));
			}
		}
		cout<<maxl;
	}
	else if(m==n-1){
		int maxl=max(qz[n-1],hz[n-1]);
		for(int i=2;i<n;i++){
			maxl=max(maxl,qz[i-1]&hz[i+1]);
		}
		cout<<maxl;
	}
	else if(f){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	else{
		cout<<0;
	}
	return 0;
}
