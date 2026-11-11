#include<bits/stdc++.h>
using namespace std;
char a[1000000000000000];
int main(){
	long long n;
	cin>>n;
	long long h=0;
	for(long long i=0;i<n;i++){
		long long m;
		cin>>m;
		char c;
		cin>>c;
		for(long long j=h;j<h+m;j++){
			a[j]=c;
		}
		h+=m;
	}
	long long cnt=0;
	for(long long i=0;i<h/2;i++){
		if(a[i]==a[h-i-1]){
			
		}
		else{
			cnt++;
		}
	}
	cout<<cnt;
}
