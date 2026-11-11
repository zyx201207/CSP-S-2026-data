#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long n,m,ans3=-1;
long long ans=-1;
long long a[N];
void dfs(long long x,long long s,long long sum){
	if(x==m){
		if(sum>=ans) ans=sum;
	}
	if(sum<ans) return;
	for(int i=s;i<=n;i++){
		dfs(x+1,i+1,sum&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long maxn=-1;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	else if(m==n){
		 long long ans1=a[1];
		for(int i=1;i<=n;i++){
			ans1=ans1&a[i];
		}
		cout<<ans1;
	}
	else if(m==2){
		 long long ans2=-1;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ans2=max(a[i]&a[j],ans2);
			}
		}
		cout<<ans2;
	}
	//else if(m==n-1){
	//	long long ans3=
	//	
	//}
	else{
		dfs(0,1,0x3f3f3f3f);
		cout<<ans;
	}
	//else{
	//	long long min2=-1;
	//	sort(a+1,a+1+n);
	//	cout<<a[n-m+1];
	//}
	
	return 0;
}
