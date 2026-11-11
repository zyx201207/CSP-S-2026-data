#include<bits/stdc++.h>
using namespace std;
long long s1[200000006];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a[200006];
	cin>>n;
	char c[200006];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long p=0;
	for(int i=1;i<=n;i++){
		p+=a[i];
	}
	long long m=0,q=0;
	for(int i=1;i<n+1;i++){
		for(long long j=1;j<a[i]+1;j++){
			m++;
			s1[m]=c[i];
		}
	} 
	long long cnt=0;
	for(long long i=1;i<p/2+1;i++){
		if(s1[i]!=s1[p-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
