#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2e5+5;
int a[N],v[N],n,m,ans=0;
bool cpd(int x,int y){
	return x>y;
}
void check(){
	int sum=2147483647;
	for(int i=1;i<=n;i++){
		if(v[i]==1) {
			sum=sum&a[i];
		}
	}
	ans=max(ans,sum);
}
void dfs(int x,int sum){
	if(x>n) return;
	v[x]=1,sum++;
	dfs(x+1,sum);
	if(sum==m){
		check();
		return;
	}
	v[x]=0;
	dfs(x+1,sum-1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20) dfs(1,0);
	else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}
	else if(m==n){
		for(int i=1;i<=n;i++) v[i]=1;
		check();
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,int(a[i]&a[j]));
			}
		}
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			v[i]=0;
			check();
			v[i]=1;
		}
	}
	else{
		sort(a+1,a+n+1,cpd);
		ans=a[m];
	}
	cout<<ans;
	return 0;
}

