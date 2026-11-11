#include<bits/stdc++.h>
using namespace std;

long long n;
long long z;
long long a;
long long sum;
char c;
string s="";

int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		z+=a;
		while(a--){
			s+=c;
		}
	}
	for(long long i=0;i<=z/2;i++){
		if(s[i]!=s[n-i+1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
