#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string,out","w",stdout);
	long long n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	} 
	long long q=0,w=n-1;
	long long a[n];
	char b[n];
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	long long sum=0;
	for(long long i=0;i<n/2+n%2;i++){
		if(b[q]!=b[w]){
			sum+=min(a[q],a[w]);
		}
		if(a[q]>a[w]){
			a[q]-=a[w];
			w--;
		}
		else if(a[q]<a[w]){
			a[w]-=a[q];
			q++;
		}
		else if(a[q]==a[w]){
			w--;
			q++;
		}
		if(w==q){
			break;
		}
	}
	cout<<sum;
	return 0;
}
