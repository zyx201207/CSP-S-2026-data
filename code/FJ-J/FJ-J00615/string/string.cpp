#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,s=0,z=0;
	char c1,c[999999];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c1;
		for(int j=s;j<a+s;j++){
		    c[j]=c1;
	}
	s+=a;
	}
	for(int i=0;i<s/2;i++){
		if(c[s-i-1]!=c[i]) z++;
	}
	cout<<z;
	return 0;
}


