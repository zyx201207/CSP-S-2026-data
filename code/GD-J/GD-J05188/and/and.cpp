#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],ans,z,maxx;
void dfs(int x){
	if(ans==m){
		maxx=max(z,maxx);
		return;
	}else if(x>n){
		return;
	}
	b[x]=1;
	long long q=z;
	if(z==0)z=a[x];
	else z=(z&a[x]);
	ans++;
	dfs(x+1);
	z=q;
	b[x]=0;
	ans--;
	dfs(x+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","out",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}cout<<maxx;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long s=(a[i]&a[j]);
				maxx=max(maxx,s);
			}
		}cout<<maxx;
	}else if(n==m){
		long long sum=a[1];
		for(int i=2;i<=n;i++){
			sum=(sum&a[i]);
		}cout<<sum;
	}else{
		dfs(1);
		cout<<maxx;
	}
	return 0;
} 
