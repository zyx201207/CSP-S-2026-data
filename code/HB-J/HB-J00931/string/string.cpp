#include<bits/stdc++.h>
using namespace std
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,c=0,cs=0;
    cin>>n;
    long long a[n+5],b[n+5];
    for(long long i=0;i<n;i++){
	    cin>>a[i]>>b[i];
	}
	for(long long i=0;i<n;i++){
	    c+=a[i];
	}
	char nb[c+5];
	for(long long i=0;i<n;i++){
	    for(long long j=0;j<a[i];j++){
		    nb[i]=b[i];
		}
	}
	for(long long i=0;i<c/2;i++){
	    if(nb[0+i]!=nb[c-i]) cs++;
	}
	cout<<cs;
    return 0;
}
