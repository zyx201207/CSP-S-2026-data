#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[500005],s[500005],st=1,ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		while(st<i&&a[i]*(i-st+1)-m>s[i]-s[st-1]){
			st++;
		}
		ans=max(ans,i-st+1);
	}
	cout<<ans;
	
	
	return 0;
}
