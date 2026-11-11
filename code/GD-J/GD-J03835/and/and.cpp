#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],sm=-99999;
bool f[200010];
void dfs(long long k,long long s,long long q){
	if(k==m){
		sm=max(sm,s);
//		cout<<s<<endl;
		return;
	}
	for(int i=q+1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			dfs(k+1,s&a[i],q); 
			f[i]=0;
		}
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f[1]=1;
	for(long long i=1;i<=n;i++){
		dfs(1,a[i],i);
	}
	
	cout<<sm;
//	cout<<"########"<<sm;
	return 0;
}

