#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==2){
		if(a[n]=a[n-1]){
			cout<<a[n];
		}else{
			int sn=max(a[n-2]&a[n-1],a[n-1]+a[n]);
			cout<<sn;
		}
	}else{
		cout<<a[n];
	}
	return 0;
} 
