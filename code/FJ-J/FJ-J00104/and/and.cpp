#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long mx=0;
	bool f=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (mx=0) mx=a[i];
		else mx=max(a[i],mx);
		if (i>=3&&a[i]!=(a[i-1]+a[i-2])){
			f=1;
		}
	}
	if (f==0){
		cout<<mx;
		return 0;
	}
	else{
		cout<<mx;
	}
	
	
} 
