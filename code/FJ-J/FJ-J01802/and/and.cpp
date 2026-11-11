#include <bits/stdc++.h> 
using namespace std;

long long a[200005];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long n,m;
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long l=n,mx=0;
	for(int i=0;i<l-1;i++){
		mx=max(a[i]&a[i+1],mx);
	}
	cout<<mx;
	
	
	return 0;
}


