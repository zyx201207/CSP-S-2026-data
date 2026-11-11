#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N],n,mx,m;
void dfs(int x,int sum,int k){
//	cout<<x<<"\n";
	if(k==m){
		mx=max(mx,sum);
		return ;
	}
	if(x>n)return ;
	if(k==0){
		dfs(x+1,a[x],k+1);
		dfs(x+1,0,k);
	}else{
		
		dfs(x+1,sum&a[x],k+1);
		dfs(x+1,sum,k);
	}
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//cout<<n;
	if(n<=20){
		dfs(1,0,0); 
		cout<<mx;
		return 0;
	}
	if(n==m){
		int cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt&=a[i];
		}
		cout<<cnt;
	}else if(m==0){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
	}else if(m==2){
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(a[i]&a[j],mx);
			}
		}
		cout<<mx;
	}else{
		cout<<0;
	}
}
/*


4 2
3 15 12 12


4 3
1 2 1 3



5 3
31 3 1 15 2




*/
