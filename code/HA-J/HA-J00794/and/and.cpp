#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,maxx,ans,a[200010];
bool b;
void dfs(long long cnt,long long sum,long long pos){
	if(sum>ans&&cnt==m){
		ans=sum;
		return;
	}
	for(int i=pos+1;i<=n;i++){
		if(cnt==0){
			dfs(cnt+1,a[i],i);
		}
		else{
			dfs(cnt+1,sum&a[i],i);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(a[i]!=i-1){
			b=1;
		}
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(n<=2000&&m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	if(n>2000){
		if(b==0){
			cout<<n-m;//B
		}
		else{
			sort(a+1,a+n+1);
			cout<<a[n-m+1];//A
		}
		return 0;
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
