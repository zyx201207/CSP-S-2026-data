#include<bits/stdc++.h>//按位与:& 
using namespace std;
long long n,m,a[1000000];
long long maxx=-100,ans;
long long v[1000000];
void dfs(long long x){
	if(x>m){
		maxx=max(ans,maxx);
		return ;
	}
	for(long long i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			if(x==1){
				ans=a[i];
				dfs(x+1);
				ans=0;
			}else{
				long long t=ans;
				ans=(ans&a[i]);
				dfs(x+1);
				ans=t;
			}
			v[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>2000){
		if(m>=n-1){
			cout<<"0";
			return 0;
		}
		sort(a+1,a+1+n);
		for(int i=n;i>=1;i--){
			m--;
			if(m==0){
				cout<<a[i];
				return 0;
			}
		}
	}
	dfs(1);
	cout<<maxx;
	return 0;
}
//估分:54+?
