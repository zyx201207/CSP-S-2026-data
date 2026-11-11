#include<iostream>
#include<string.h>
using namespace std;
string S;
long long n; 
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			S+=c;
		}
	}
	long long l=S.size()-1;
	for(long long i=0;i<(l+1)/2;i++){
		if(S[i]!=S[l-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
