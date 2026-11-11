#include<bits/stdc++.h>
using namespace std;
long long f[1000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0,t,k;
	cin>>t;
	k=t;
	string s="";
	while(t--){
		long long a;
		char b;
		cin>>a>>b;
		f[k-t]=a;
		for(int i=1;i<=a;i++){
			s+=b;
		}
	}
	long long l=s.size();
	for(int i=0;i<l/2;i++){
		char a=s[i],b=s[l-i-1];
		if(a!=b){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
