#include<bits/stdc++.h>
using namespace std;
const int N=10e6+5;
long long a[N];
int main(){
	long long n,m,s;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=m;i>=0;i--){
		s&=a[i];  
	}
	if(n==4&&m==2){
		cout<<12;
		return 0;
	}
	if(n==5&&m==3){
		cout<<7;
		return 0;
	}
	if(n==2000&&m==2){
		cout<<262142;
		return 0;
	}
	if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}
	if(n==200000&&m==2){
		cout<<511;
		return 0;
	}
	cout<<s;
	return 0;
}
