#include <bits/stdc++.h>
using namespace std;
long long m,ans=0,f,n;
int a[500003];
long long qw(long long x){
	f=m;
	int r=a[x],p=1;
	for(int i=x-1;i>=1;i--){
		if((r-a[i])>f){
			return p;
		}else{
			f-=(r-a[i]);
			p++;
		}
	}
	return x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ans=max(ans,qw(i));
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
