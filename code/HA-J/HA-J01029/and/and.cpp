#include<bits/stdc++.h>
using namespace std;
long long a[200005];
	long long n,m,ans=1,mx=-1,ans2=1,fin=-1;
//now look nw,have chosen l,the ans is k
void dfs(long long nw,long long l,long long k){
	if(nw>n)return;
	if(l==m){
		fin=max(fin,k);
		return;
	}
	if(n-nw<m-l)return;
	dfs(nw+1,l+1,k&a[nw]);
	dfs(nw+1,l,k);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==n){//6
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){//7
		cout<<mx;
		return 0;
	}
	if(m==2&&(n*n<pow(10,8)*2)){//8~10
		mx=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,(a[i]&a[j]));
			}
		}
		cout<<mx;
		return 0;
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		ans&=a[i];
	}cout<<ans;
	return 0;
}//4 2
//3 15 12 12

