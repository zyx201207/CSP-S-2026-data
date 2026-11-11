#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s=0,x=0,l=0;
	cin>>n;
	long long t[n];
	char c[n];
	for(long long i=0;i<n;i++){
		cin>>t[i]>>c[i];
		s+=t[i];
	}
	string a[s];
	for(long long i=0;i<n;i++){
		while(t[i]--){
			a[l]=c[i];
			l++;
		}
	}
	for(long long i=0;i<s/2;i++){
		if(a[i]!=a[s-i-1]){
			a[s-i-1]=a[i];
			x++;
		}
	}
	cout<<x;
	return 0;
}
