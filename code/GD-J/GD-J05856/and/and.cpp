#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1234567],b[1234567];
long long maxx;
bool vis[1234567];
void dfs(long long d,long long sum){
	//cout<<d<<" "<<sum<<"\n";
	if(d==m+1){
		/*cout<<d<<" "<<sum<<":";
		for(int i=1;i<d;i++){
			cout<<b[i]<<" ";
		}cout<<endl;*/
		maxx=max(maxx,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[d]=a[i];
			if(d==1)dfs(d+1,a[i]);
			else dfs(d+1,sum&a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==2){
		maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(a[i]&a[j],maxx);
			}
		}
		cout<<maxx;
		return 0;
	}
	maxx=-1;
	dfs(1,0);
	cout<<maxx;
}
