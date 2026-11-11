#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200024];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==m){
		ans=a[1];
		for(int i=1;i<=n;i++)ans&=a[i];
		cout<<ans<<endl;
		return 0;
	}sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n]<<endl;
		return 0;
	}else if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)maxn=max(maxn,a[i]&a[j]);
		}cout<<maxn<<endl;
		return 0;
	}if(n-1==m){
		int maxn=0;
		ans=a[2];
		for(int i=3;i<=n;i++)ans&=a[i];
		maxn=max(maxn,ans);
		for(int i=2;i<=n;i++){
			ans=a[1];
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				else ans&=a[i];
			}maxn=max(maxn,ans);
		}cout<<maxn<<endl;
		return 0;
	}
	ans=a[n];
	for(int i=n-1;i>=n-m+1;i--)ans&=a[i];
	cout<<ans<<endl;
	return 0;
}
