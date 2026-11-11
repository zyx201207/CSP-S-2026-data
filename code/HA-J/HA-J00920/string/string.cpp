#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	if(n==1){
		int a;char b;
		cin>>a>>b;
		cout<<0;
		return 0;
	}
	if(n==2){
		int a,b;char c,d;
		cin>>a>>c>>b>>d;
		if(c!=d){
			cout<<min(a,b);
		}else{
			cout<<0;
		}
		return 0;
	}
}
