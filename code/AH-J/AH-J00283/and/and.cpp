#include<bits/stdc++.h>
using namespace std;
int m,n,d,b[10005],ans[35],h[35]={0,1};
bool a[10005][35],mx[35],q[35];
long long  s;
void dfs(int k,int l){
	if(k==m){
		for(int i=32;i>=1;i++){
			if(q[i]>mx[i]){
				for(int j=1;j<=30;j++){
					mx[i]=q[i];
				}
				break;
			}
		}
		return;
	}
	for(int i=1;i<=l;i++){
		if(q[i]==a[k][i]){
			q[i]=1;
		}else{
			q[i]=0;
		}
	}
	for(int i=k+1;i<=n;i++){
		d=max(b[i],l);
		dfs(i,d);
		d=b[i];
	}
	for(int i=1;i<=l;i++){
		if(q[i]==a[k][i]){
			q[i]=1;
		}else{
			q[i]=0;
		}
	} 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=1;j<10005;j++){
			a[i][j]=s%2;
			s/=2;
			b[i]=j;
		}
	}
	for(int i=1;i<=n-m+1;i++){
		dfs(i,1);
	}
	int u=1;
	for(int i=1;i<=n;i++){
		s=mx[i];
		for(int j=1;s<10000000;j++){
			ans[i]=s%5;
		
			s*=5;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i];
	}
}
