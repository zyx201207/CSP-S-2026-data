#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
string sd;
long long s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++) sd=sd+c[i];
		s+=a[i];
	}
	s/=2;
	for(int i=1;i<=s;i++){ 
	    if(sd[i]!=sd[i+s]) s1++;
	}
	cout<<s1;
	return 0;
}
//Trick||Treat!
