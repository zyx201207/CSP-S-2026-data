#include<bits/stdc++.h>
using namespace std;
char b[200000000000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int k,a;
	long long cnt=1;
	char c;
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			b[cnt]=c;
			cnt++;
		}
	}
	long long n=1,m=cnt-1,num=0;
	for(long long i=1;i<=(cnt-1)/2;i++){
		if(b[n]!=b[m]) num++;
		n++;
		m--;
	}
	cout<<num;
	return 0;
} 
