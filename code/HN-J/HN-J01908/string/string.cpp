#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s;
	long long ans=0,r=0,l=1;
	int a[200005];
	char b[200005];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		r+=a[i];
	}
	long long i=1,j=0;
	long long ii=n,jj=0;
	while(l<=r){
		j++;
		jj++;
		if(a[ii]<=jj){
			jj=0;
			ii--;
		}
		if(a[i]<=j){
			j=0;
			i++;
		}
		if(b[i]!=b[ii]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
