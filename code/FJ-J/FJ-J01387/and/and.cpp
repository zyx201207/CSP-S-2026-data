#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10; 
int n,m;
int a[N];
bool cmp(int i,int j){
	return i>j;
}
int ans=-1;
void dfs(int k,int d,int tmp){
	if(d==m){
		ans=max(ans,tmp);
		return ;
	}
	for(int i=k+1;i<=n-m+d+1;i++){
		dfs(i,d+1,tmp&a[i]);
	}
}
int maxn=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
	}
	else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			} 
		}
		cout<<ans;
	}
	else if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else if(maxn<4){
		int b[4]={0};
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		if(b[3]>=m) cout<<3;
		else if(b[3]+b[2]>=m) cout<<2;
		else if(b[3]+b[1]>=m) cout<<1;
		else cout<<0;
	}
	else if(n<=20){
		dfs(0,0,pow(2,20)-1);
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
