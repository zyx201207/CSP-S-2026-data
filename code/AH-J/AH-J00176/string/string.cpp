#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	long long n;
	cin>>n;
	if(n==2){
		int a,aa;
		string b,bb;
		cin>>a>>b>>aa>>bb;
		int pp=min(a,aa);
		if((a+aa)%2==0){
			int bs=(a+aa)/2-pp;
			cout<<bs;
		}if((a+aa)%2==1){
			int bs=(a+aa)/2+1-pp;
			cout<<bs;
		}
		
	}
	
	if(n==1){
		cout<<0;
		return 0;
	}
}
