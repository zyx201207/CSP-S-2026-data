#include<bits/stdc++.h>
using namespace std;
int n,m,mx,w[200005][35],d[35];
long long a[200005],ans,v[200005],v2[200005],t;
void dfs(int k,int s,long long c){
	if(s==m+1){
		ans=max(ans,c);
		return;
	}
	if(k>n) return;
	long long d;
	if(s==1){
		d=a[k];
	}else{
		d=(c&a[k]);
	}
	dfs(k+1,s+1,d);
	dfs(k+1,s,c);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[++t]=i;
	}
	if(n<=20){
		dfs(1,1,0);
		cout<<ans;
	}else if(m==1){
		long long mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
	}else if(n<=2000&&m==2){
		long long mx=0;
		for(int i=1;i<=n;i++){
			ans=a[i];
			for(int j=i+1;j<=n;j++){
				mx=max(mx,(ans&a[j]));
			}
		}
		cout<<mx;
	}else{
		for(int i=1;i<=n;i++){
			int cnt=0;
			while(a[i]){
				w[i][++cnt]=a[i]%2;
				a[i]/=2;
			}
			mx=max(mx,cnt);
		}
		for(int j=mx;j>=1;j--){
			int cnt=0,tt=0;
			for(int i=1;i<=t;i++){
				int k=v[i];
				if(w[k][j]==1){
					cnt++;
					v2[++tt]=k;
				}
			}
			if(cnt>=m){
				d[j]=1;
				for(int i=1;i<=tt;i++){
					v[i]=v2[i];
				}
				t=tt;
			}
		}
		long long base=2,ans=0;
		for(int i=mx;i>=1;i--){
			ans=ans*base+d[i];
		}
		cout<<ans;
	}
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

4 3
15 12 12 3

4 4
1 3 7 15
*/

