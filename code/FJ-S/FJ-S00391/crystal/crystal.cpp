#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int f,maxx=-1,l,ans,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]!=a[i-1]){
			f=1;
		} 
	}
	if(f==0){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		l=i;ans=1;sum=0;
		while(l>1&&sum+(a[i]-a[l-1])<=m){
			l--;
			ans++;
			sum+=(a[i]-a[l]);
		}
		if(ans>maxx){
			maxx=ans;
		}
	}
	cout<<maxx;
	return 0;
}
