#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],s[500005],ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		s[i]=a[i]-a[i-1];
	}
	long long i=1,j=1,x=0;
	while(j<=n){
		if(x<=m){
			ans=max(ans,j-i+1);
			j++;
			x+=(j-i)*s[j];
		}
		else{
			x-=a[j]-a[i];
			i++;
		}
	}
	cout<<ans;
}
