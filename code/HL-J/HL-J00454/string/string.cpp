#include<bits/stdc++.h>
using namespace std;
long long a;
char c;
int y[100000005]={0};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long s=0;
	long long lx=1;
	for(long long i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		s+=a;
		for(long long j=1;j<=a;j++){
			y[lx++]=int(c);
		}
	}
	long long l=1,r=lx-1;
	while(l<=r){
		if(y[l]!=y[r]){
			cout<<s-ceil(s*1.0/2);
			return 0;
		}
		l++;
		r--;
	}
	cout<<"0";
	return 0;
}
