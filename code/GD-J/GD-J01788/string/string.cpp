#include<bits/stdc++.h>
using namespace std;
long long a,c=0,b,d=0;
//long long q[2000000000001];
unsigned char st[100000001];
char s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(long long i=1;i<=a;i++){
		cin>>b>>s;
		for(int j=c+1;j<=c+b+1;j++){
			st[j]=s;
		}
		c+=b;
	}
	for(long long i=1;i<=c/2;i++){
		long long j=c;
		if(st[i]!=st[j]) d++;
		j--;
	}
	cout<<d;
	return 0;
}
