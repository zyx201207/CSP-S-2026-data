#include<bits/stdc++.h>
using namespace std;
long long n;
string a;
string b;
long long lenchang;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long o;
	char p;
	for(int i=1;i<=n;i++){
		cin>>o;
		lenchang+=o;
		cin>>p;
		for(int i=1;i<=o;i++){
			a=a+p;
			b=p+b;
		} 
	} 
	lenchang=lenchang/2;
	for(int i=0;i<=lenchang;i++){
		if(a[i]!=b[i]){
			ans++;
		}
	} 
	cout<<ans;
	return 0;
} 
