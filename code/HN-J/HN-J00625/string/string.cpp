#include <bits/stdc++.h>
using namespace std;
string a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	int n;
	cin>>n;
	int len=0;
	int t;
	string c;
	for (int i=1;i<=n;i++){		
		cin>>t>>c;
		len+=t;
		while(t--){
			a+=c;
		} 
	}
	long long x=0;
	for (int i=0;i<len/2;i++){
		if(a[i]!=a[len-i-1]){
			x++;	
		}
	}
	cout<<x;
	return 0;
} 
