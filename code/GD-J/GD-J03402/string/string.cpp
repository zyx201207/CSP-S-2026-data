#include<bits/stdc++.h>
using namespace std;
string n;
int main(){
	freopen("string.in","r",stdin);
	freopen("srring.out","w",stdout);
	long long  a,m=1,all=0;
	cin>>a;
	for(int i=1;i<=a;i++){
		long long b;
		char cd;
		cin>>b>>cd;
		long long w=b; 
		while(b--){
			n+=cd;
		}
		all+=w;
	}
	m=0;
	long long ans=0;
	for(int i=all-1;i>=0;i--){
		if(n[m]!=n[i]){
			ans++;
		}
		m++;
	}
	cout<<ans/2;
	return 0;
}
