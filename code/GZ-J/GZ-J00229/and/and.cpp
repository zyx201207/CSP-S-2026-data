//GZ-J00229 观山湖区铭苑中学 徐梓耀
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,cnt[35];
long long a[N],b=INT_MAX,ans,maxx,x;
void dfs(int num,int step,long long ans){
	if(step==n){
		if(num==m) x=max(x,ans);
		return;
	}
	for(int i=step+1;i<=n;i++){
		dfs(num,i,ans),dfs(num+1,i,ans&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b&=a[i],maxx=max(maxx,a[i]);
	}
	if(m==1) cout<<maxx;//6
	else if(m==2){//8-10
		maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	else if(n==m) cout<<b;//7
	else if(n<=20){//1-5
		dfs(0,0,INT_MAX);
		cout<<x;
	}
	else{
		sort(a+1,a+1+n,greater<int>());
		maxx=INT_MAX;
		for(int i=1;i<=m;i++){
			maxx&=a[i];
		}
		cout<<maxx;
	}
	return 0;
}
