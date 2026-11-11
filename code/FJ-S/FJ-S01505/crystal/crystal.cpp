#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n/2;i++){
		if(m>=a[n/2]-a[n/2-i]){
		   ans++;
		   m-=a[n/2]-a[n/2-i];
		}
		if(m>=a[n/2+i]-a[n/2]){
		   ans++;
		   m-=a[n/2+i]-a[n/2];
		}
	}
	cout<<ans;
	return 0;
}
