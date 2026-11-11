#include<bits/stdc++.h>
using namespace std;
long long n,m,f,w,maxw,z,ans,a[200010],b[21];
bool cmp(long long x,long long y){
	return x>y;
}
void dfs(long long c,long long d){
	if(c==m){
		ans=max(ans,d);
		return;
	}
	for(long long i=1;i<=n;i++){
		if(!b[i]&&d>=ans){
			b[i]=1;
			dfs(c+1,d&a[i]);
			b[i]=0;
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
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
	}
	else if(m==n){
		for(long long i=1;i<=n;i++){
			a[1]=a[1]&a[i];
		}
		cout<<a[1];
	}
	else if(m==2){
		ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(a[i]&a[j]>ans){
					ans=a[i]&a[j];
				}
			}
		}
		cout<<ans;
	}
	else if(n<=20){
		ans=0;
		for(long long i=1;i<=n;i++){
			memset(b,0,sizeof(b));
			b[i]=1;
			dfs(1,a[i]);
		}
		cout<<ans;
	}
	else{
		cout<<a[m];
	}
	return 0;
}
