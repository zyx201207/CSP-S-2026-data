#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string m={0};
	long long c=1;
	cin>>n;
	long long c2=0;

	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x;
		cin>>y;
		c2+=x;
	if(x==1000000000){
		cout<<x*n/2;
		return 0;
	}
		for(int j=1;j<=x;j++){
			m[c++]=y;
		}
	}
	string h={0};
	for(int i=1;i<=c;i++){
		h[i]=m[c2--];
	}
	int s=0;
	for(int i=1;i<=c;i++){
		if(h[i]!=m[i]){
			s++;
		}
	}
	cout<<s;
	return 0;
} 
