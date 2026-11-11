#include <bits/stdc++.h>
using namespace std;
long long n,m,a[2000005];

bool cmp(long long a,long long b){
	if(a>=b){
		return a;
	}
	return b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n,cmp);
	
	long long ans=a[1];
	for(long long i=1;i<=m;i++){
		ans=ans&a[i];
	}
	
	cout<<ans;
	return 0;
} 
