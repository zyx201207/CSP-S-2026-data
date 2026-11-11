#include<bits/stdc++.h>
using namespace std;
long long d=0,a,e=0,n;
string b,c;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>b;
		for(long long j=0;j<a;j++) c+=b;
	}
	if(n%2==1){
	for(long long i=0;i<=n;i++){
		if(c[i]==c[n/2+1]) e++;
		}}
	if(e%2==0&&e!=n) d++;
	for(int i=a;i>=n/2;i--){
		if(c[i]!=c[n-i]) d+=1;
	}
	cout<<d;

return 0;

} 

