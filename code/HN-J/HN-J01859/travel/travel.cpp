#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c,a1,c1;
	char b,d;
	cin>>a>>a1>>b>>c>>c1>>d;
	if(a==c){
		cout<<1;
		if(a1==c1){
			cout<<1;
		}else{
			cout<<"000";
			return 0;
		}
		if((b<='C'&&d<='C')||(b>='D'&&d>='D')){
			cout<<1;
			if(b+1==d||d+1==b)cout<<1;
			else cout<<0;
		}else{
			cout<<"00";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
