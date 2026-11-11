#include <bits/stdc++.h>
#include <cstdio> 
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	
	long long n,m,cnt=1,ma=-1e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int b=n/2+1;
	for(int i=b;i>1;i--){
		if(a[i]!=a[i-1]){
			long long c=a[i]-a[i-1];
			if(c<=m){
				a[i-1]+=c;
				m-=c;
			}else {
				break;	
			}
		}
	}
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1])cnt++;
	}	
	cout<<cnt;
	return 0;
}
