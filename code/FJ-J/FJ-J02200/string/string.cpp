#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	long long n,a,s,l,j=0;
	string c;
	char b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>b;
		for(int j=1;j<=a;j++){
			c+=b;
		}
	}
	if(c.size()%2==0){
		l=c.size()/2;
	}
	else{
		l=c.size()/2+1;
	}
	for(long long i=c.size();i>=l+1;i--){
		if(c[i]!=c[j]){
			s++;
		}
		j++;
	}
	cout<<s;
	return 0;
}
