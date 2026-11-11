#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[11111111];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long zd=0;
	for(int i=0;i<n;i++){
		if(zd<a[i]){
			zd=a[i];
		}
	}
	cout<<zd;
	return 0'
}
