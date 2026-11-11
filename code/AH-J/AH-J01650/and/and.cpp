#include <bits/stdc++.h>
using namespace std;
int n,m,ans=-1;
int a[200005];
void dfs(int step,int q,int count){
	if(step>n){
		if(count==m){
			ans=max(ans,q);
		}
		return ;
	}
	if(count==m){
		ans=max(ans,q);
		return ;
	}
	if(q==-1){
		dfs(step+1,a[step],count+1);
		dfs(step+1,q,count);
	}
	else{
		dfs(step+1,a[step]&q,count+1);
		dfs(step+1,q,count);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,-1,0);
		cout<<ans;
		return 0;
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int w=a[1];
		for(int i=2;i<=n;i++){
			w=w&a[i];
		}
		cout<<w;
		return 0;
	}
	if(m==2){
		int p=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				p=max(p,a[i]&a[j]);
			}
		}
		cout<<p;
		return 0;
	}
	if(m==n-1){
		int g=-1,g2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=1&&j==1){
					g2=a[1];
					continue;
				}
				if(j==1&&i==1){
					continue;
				}
				if(j==2&&i==1){
					g2=a[2];
					continue;
				}
				if(j==i){
					continue;
				}
				g2=g2&a[j];
			}
			g=max(g,g2);
		}
		cout<<g;
		return 0;
	}
	sort(a+1,a+1+n);
	if(a[n]<4){
		int t=a[n]; 
		for(int i=n-1;i>=n-m+1;i--){
			t=t&a[i];
		}	
		cout<<t;
		return 0;
	}
	cout<<n-m;
	return 0;
} 
