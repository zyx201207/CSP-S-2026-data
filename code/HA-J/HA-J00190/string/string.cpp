#include <bits/stdc++.h>
using namespace std;
char p[10000005];
int main(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long zifu;
	cin>>zifu;
	long long n=0;
	long long m=0;
	
	for(long long i=0;i<zifu;i++){
		long long cnt;
		cin>>cnt;
		
		char danyi;
		cin>>danyi;
		m+=cnt;
		while(cnt>0){
			p[n]=danyi;
			n++;
			cnt--;
		}
	}
	long long cn=0;
		for(long long i=0;i<m/2+1;i++){
		
				if(p[i]!=p[m-1])
				cn++;
				m--;
		}
	cout<<cn;

	
	return 0;
}
