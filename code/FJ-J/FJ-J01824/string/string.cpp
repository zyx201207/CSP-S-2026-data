#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin)
	freopen("string.out","w",stdout)
	int n;
	long long sum =0;
	cin>>n;
	long long a[n];
	int b[n];
	for(int i=0;i<n;i++){
		char c;
		cin>>a[i]>>c;
		b[i]=c-'a';
	}
	for(int i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			if(b[i]!=b[n-j-1-i]){
				sum++;
			}
		}
	}
	cout<<sum/2;
	return 0;
}
