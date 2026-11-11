#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e7+10;
long long sz[maxn],cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long no=1;
	for(long long i=1;i<=n;i++){
		long long a,b;
		char c;
		cin>>a>>c;
		b=c-'a'+1;
		for(long long j=no;j<=no+a-1;j++){
			sz[j]=b;
		}
		no=no+a;
	}
	for(long long i=1;i<=(no-1)/2;i++){
		long long j=(no-1)-i+1;
		if(sz[j]!=sz[i])cnt++;
	}
//	for(long long i=1;i<=(no-1);i++){
//		cout<<sz[i];
//	}
	cout<<cnt;
}

//123456789
//10 11 12 17 18 19 20 21 
