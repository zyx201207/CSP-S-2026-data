#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n,m;
unsigned long long a[MAXN]; 
bool vis[MAXN];
unsigned long long ans;
void dfs(int x,unsigned long long l){
	if(x==m){
		ans=max(ans,l);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i] and 1==1){
			vis[i]=1;
			dfs(x+1,l & a[i]);
			vis[i]=0;
		}
	}
	
	
}
bool cmp(unsigned long long x1,unsigned long long x2){
	return x1>x2;
}
int main(){
	freopen("and.in","r",stdin);//!!!
	freopen("and.out","w",stdout);//!!!
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				//cout<<a[i]<<" "<<a[j]<<endl;
				ans=max(a[j]&a[i],ans);
			}
		}
		cout<<ans;
		return 0;
	}
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(n-1==m){
		for(int i=1;i<=n;i++){
			ans=a[(i+1+n)%n];
			for(int j=1;j<=n,j!=i;j++){
				ans&=a[j];
			}
		}
		cout<<ans;
		return 0;
	}
	/*for(int i=1;i<=n;i++){
		dfs(1,a[i]);
	}
	cout<<ans;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=b;j++){
			
		}
	}*/
	return 0;
} 
