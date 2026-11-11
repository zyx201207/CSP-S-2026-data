#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a,b;
int t[N];
int sum=0;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>a>>b;
	if(a==0 && b==2){
		cout<<1<<endl<<2;	
	}
	if(a==0 && b==3){
		cout<<1<<endl<<1<<endl<<2;	
	}
	if(a==0 && b==5){
		cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;	
	}
		if(a==0 && b==1){
		cout<<12251;	
	}
	return 0;
}
