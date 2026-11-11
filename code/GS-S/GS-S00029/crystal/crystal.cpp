#include <bits/stdc++.h>
using namespace std;
long long n,m,a[50005],ans,anss;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long b=a[n/2+1],c=n/2+1;
	for(int i=c;i>=1;i--){
		ans+=(b-a[i]);
		if(ans<=m)anss++;
		else{
			cout<<anss;
			return 0;
		}
	}
	for(int i=c+1;i<=n;i++){
		ans+=(a[i]-b);
		if(ans<=m)anss++;
		else{
			cout<<anss;
			return 0;
		}
	}
	cout<<anss;
	return 0;
} 
