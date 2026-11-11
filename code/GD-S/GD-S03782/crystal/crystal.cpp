#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i+=1){
		cin>>a[i];
	}
	long long b=0;
	long long cnt=0;
	for(int i=1;i<=n;i+=1){
		b+=i;
		if(b>m){
			cout<<cnt;
			return 0;
		}
		cnt++;
	}
	return 0;
}

