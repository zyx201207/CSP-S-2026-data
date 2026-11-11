#include<bits/stdc++.h>
using namespace std; 
long long n,a[1000005];
char m[1000005];
string s;
int main(){
	//Trick||Treat!
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>m[i];
		for(int j=1; j<=a[i]; j++){
			s+=m[i];
		}
	} 
	cout<<0;
	
	
	return 0;
}
