#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500006],b[500006],c[5000006];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	long long ss=1;
	for(long long i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			b[i]=b[i-1];
		}
		else{
			b[i]=c[i]*(i-1)+b[i-1];
		}
		if(b[i]<=m){
			ss=i;
		}
		if(b[i]>m){
			break;
		} 
	}
	cout<<ss;
	return 0;
} 
