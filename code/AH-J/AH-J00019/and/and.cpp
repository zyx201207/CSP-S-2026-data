#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,maxn,ans,a[N];
bool f;
void dfs(int x,int k,int sum){
	//cout<<x<<" "<<k<<" "<<sum<<endl;
	if(x>=m){
		ans=max(ans,sum);
		//cout<<ans<<endl;
		return;
	}
	for(int i=k+1;i<=n;i++){
		if((sum&a[i])>ans) dfs(x+1,i,sum&a[i]);
	}
	return;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		double x=log2(a[i]+1);
		if(x!=int(x)) f=1;
	}
	if(m==1){
		ans=maxn;
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
	}
	else if(maxn<4){
		int t[5];
		for(int i=1;i<=n;i++) t[a[i]]++;
		if(t[3]>=m) ans=3;
		else if(t[3]+t[2]>=m) ans=2;
		else if(t[3]+t[1]>=m) ans=1;
		else ans=0;
	}
	else if(!f){
		sort(a+1,a+n+1,cmp);
		ans=INT_MAX;
		for(int i=1;i<=m;i++) ans&=a[i];
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else{
		dfs(0,0,INT_MAX);
	}
	cout<<ans;
	return 0;
}
//理想65分
