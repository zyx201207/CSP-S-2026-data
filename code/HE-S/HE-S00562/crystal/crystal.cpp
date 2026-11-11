#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	int a[n+1];
	cin>>a[1];
	long q[n+1];
	q[1]=0;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		q[i]=(a[i]-a[i-1])*(i-1)+q[i-1];
	}
	for(int i=1;i<=n;i++){
		if(q[i]>m){
			cout<<i-1;
			return 0;
		}
	}
	
	return 0;
} 
