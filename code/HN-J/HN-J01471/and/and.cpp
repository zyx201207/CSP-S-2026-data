#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n;
	cin>>n;
	long long s[1111]={0};
	long long b=0;
	long long amx=0;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		if(i==1){
		s[0]+=a%2;
		}
		n+=a/2;
		s[i]+=n%2;
		if(s[i]>=amx){
			amx=s[i];
		}
		if(i==n){
			cout<<s;
		}
	}
	return 0;
}
