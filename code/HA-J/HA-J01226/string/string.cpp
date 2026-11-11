#include<bits/stdc++.h>
using namespace std;
int main(){
//freooen("string.in","r",stdin);
//freopen("string.out","w",stdout);
	long long n,l[1000],k=0,j=0,m=0;
	cin>>n;
	string a,h;
	for(int i=0;i<n;i++){
		cin>>l[i];
		m+=l[i];
			cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		for(long long s=0;s<l[i];s++){
			h[k]=a[i];
			k++;
		}
	}
	for(long long i=0;i<m/2+1;i++){
		char o;
		if(h[i]!=h[m-i-1]){
			h[i+1]=o;
			h[i+1]=h[m-i-1];
			h[n-i-1]=o;
			j++;
		}
	}
	cout<<j;
	return 0;
}
