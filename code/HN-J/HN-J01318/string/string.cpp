#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c,d;
	int n,a,b;
	cin>>n>>a>>c>>b>>d;
	if(n==1){
		cout<<0;
	}
	if(n==2&&c==d){
		cout<<0;
	}
	if(n==2&&c!=d){
		if(a==b){
			cout<<0;
		}
		else if(a>b){
			cout<<b;
		}
		else if(a<b){
			cout<<a;
		}	
	}
	return 0;
} 
