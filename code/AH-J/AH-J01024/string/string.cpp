#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],s=0,f;
char b;
string final="";
int check(string k){
	long long h=k.size();
	for(int i=0;i<h;i++){
		if(k[i]!=k[h-i-1])return 0;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b;
		for(int j=1;j<=a[i];j++){
			final+=b;
		}
	}
	f=final.size();
	if(check(final)==1){
		cout<<0;
		return 0;
	} 
	else {
		for(int i=0;i<(long long)ceil(f/2);i++){
			if(final[i]!=final[f-i-1])s++;
		}
		cout<<s;
	}
	return 0;
} 
