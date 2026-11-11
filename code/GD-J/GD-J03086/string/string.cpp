#include<bits/stdc++.h>
using namespace std;
long long n,gai,x[200500];
char y[200500];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	long long r=1,l=n;
	while(r!=n&&r+1!=l){
		if(y[r]!=y[l]){
			gai+=min(x[r],x[l]);
		}
		if(x[r]>x[l]){
			x[r]-=x[l];
			l--;
		} 
		else if(x[r]<x[l]){
			x[l]-=x[r];
			r++;
		}
		else if(x[r]==x[l]){
			r++;
			l--;
		}
	}
	cout<<gai;
	return 0;
} 
