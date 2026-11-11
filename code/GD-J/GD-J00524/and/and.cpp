#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],cnt,b=1073741823;
void dfs(long long k){
	if(k==m){
		cnt=max(cnt,b);
		return ;
	}
	int t=b;
	for(int i=1;i<=n;i++){
		b=b&a[i];
		dfs(k++);
		b=t;//»ØËÝ 
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	long long sum=a[1],ans=a[1];
	for(long long i=2;i<=n;i++){
		cin>>a[i];
		sum=max(sum,a[i]);
		ans=ans&a[i];
	}
	if(m==n){
		cout<<ans;
		return 0;
	}
	else if(m==1){
		cout<<sum;
		return 0;
	}
	else{
		dfs(0);
		cout<<cnt;
	}
	return 0;
} 
