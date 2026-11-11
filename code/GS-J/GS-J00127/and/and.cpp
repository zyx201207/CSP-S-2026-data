#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[200005];
bool cmp(int x,int y){
	return x>y;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1)cout<<a[1];
	else if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=a[i]&ans;
		}
		cout<<ans;
	}
	else if(m==2){
		long long maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
			
		}
		cout<<maxn;
	}
	else{
		long long ans1=a[1];
		for(int i=2;i<=m;i++){
			ans1=a[i]&ans1;
		}
		cout<<ans1;
	}
	return 0;
}
