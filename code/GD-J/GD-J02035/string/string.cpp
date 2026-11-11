#include <iostream>
using namespace std; 

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	if(n == 2){
		long long m=0;
		long long q =0;
		char q1;
		char m1;
		cin>>m>>m1;
		cin>>q>>q1;
		if (m==q){
		cout<<"0"<<endl;
		return 0;
		}
		if(m>q){
			cout<<q<<endl;
			return 0;
		}else{
			cout<<m<<endl;
			return 0;
		}
	}
	if (n==1){
		cout<<"0"<<endl;
		return 0;
	}
	string s,d;
	long long g[n]={0};
	long long h=0;
	for(long long i=0;i<n;i++){
		long long a;
		char c;
		cin >>a>>c;
		h =a+h;
		g [i]=a;
		for(long long p =0;p<a;p++){
			s=s+c;
		}
	}
	for(long long r = h;r>0;r--) {
		d=d+s[r-1];
	}
	long long ty=0;
	for(long long a=0;a<h;a++){
		if(d[a]!=s[a]){
			ty=ty+1;
		}
	}
	cout<<ty/2<<endl;
	return 0;
}
