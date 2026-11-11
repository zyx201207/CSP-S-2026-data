#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],mx;
void dfs(long long x,long long y,long long cnt){
	if(y==0){
		mx=max(mx,cnt);
		return;
	}
	for(long long i=x+1;i<=n-y+1;i++)dfs(i,y-1,(cnt&a[i]));
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		long long mx=0;
		for(long long i=1;i<=n;i++)mx=max(mx,a[i]);
		cout<<mx;
	}else if(m==n){
		long long cnt=a[1];
		for(long long i=1;i<=n;i++)cnt=(cnt&a[i]);
		cout<<cnt;
	}else if(m==n-1){
		long long mx=0;
		for(int i=1;i<=n;i++){
			long long cnt=-1;
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				if(cnt==-1)cnt=a[j];
				else cnt=(cnt&a[j]);
			}
			mx=max(mx,cnt);
		}
		cout<<mx;
	}
	m--;
	for(long long i=1;i<=n-m;i++){
		dfs(i,m,a[i]);
	}
	cout<<mx;
	return 0;
} 
