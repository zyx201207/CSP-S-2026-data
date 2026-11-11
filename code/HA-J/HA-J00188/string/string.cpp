#include<bits/stdc++.h>
using namespace std;
long long n,p=1,h=0,g=0,cnt=0;
long long a[200010];
string d;
char c[1000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1]){
			p=0;
		}
	}
	if(n==1||p){
		cout<<0;
		return 0;
	}
	long long k=n/2;
	for(long long i=0;i<k-1;i++){
		if(a[i]==a[i+1]&&c[i]==c[i+1]){
			h=1;
		}
	}
	for(long long i=k;i<n-1;i++){
		if(a[i]==a[i+1]&&c[i]==c[i+1]){
			g=1;
		}
	}
	if(h==1&&g==1){
		cout<<k*a[1];
		return 0;
	}
	long long t=0;
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			d+=c[i];
			t++;
		}
	}
	//t--;
//	for(int i=0;i<t;i++){
//		cout<<d[i];
//	}
	for(long long i=0;i<(t+1)/2;i++){
		if(d[i]!=d[t-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;

}
