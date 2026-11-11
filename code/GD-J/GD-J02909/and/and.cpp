#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int a[N],n,m,ans=-1;
void dfs(int last,int chs,int sum){
	if(chs==m){
		ans=max(sum,ans);
		return;
	}
	for(int i=last+1;i<=n;i++){
		dfs(i,chs+1,sum&a[i]);
	}
}
int main(){
	//¼ì²éfreopenÊÇ·ñ±»×¢ÊÍ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>20&&n<=2000){
		if(m==1){
			sort(a+1,a+1+n);
			cout<<a[n];
			return 0;
		}
		if(m==2){
			for(int i=1;i<=n;i++){
				dfs(i,1,a[i]);
			}
			cout<<ans;
			return 0;
		}
		int ss=a[1];
		for(int i=2;i<=n;i++){
			ss&=a[i];
		}
		cout<<ss;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(i,1,a[i]);
	}
	cout<<ans;
	return 0;
}
