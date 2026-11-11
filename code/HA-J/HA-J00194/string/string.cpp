#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n];
	string c[n],str;
	for(long long i=0;i<=n-1;i++){
		cin>>a[i]>>c[i];
		for(long long y=1;y<=a[i];y++){
			str=str+c[i];
		}
	}
	int b=0;
	for(long long i=0;i<=floor(str.size()/2)-1;i++){
		if(str[i]!=str[(str.size()-1)/2]) b++;
	}
	cout<<b; 
	return 0;}
