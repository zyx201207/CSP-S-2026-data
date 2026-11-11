#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a,b,c,d,e,f,g,h,k,l;
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>k>>l;
	if(a==f){
		if(b==g){
			cout<<1;
		}else{
			cout<<"0000";
			return 0;
		}
	}
	if(c==h){
		if(d==k){
			cout<<1;	
		}else{
			cout<<"000";
			return 0;
		}
	}
		
	if(e>='D'){
		if(l>='D'){
			cout<<"11";
			return 0;
		}
	}
	if(e=='D'){
		cout<<"00";
		return 0;
	}
	if(e=='F'){
		cout<<"00";
		return 0;
	}
	if(l=='D'){
		cout<<"00";
		return 0;
	}
	if(l=='F'){
		cout<<"00";
		return 0;
	}
	if(e=='A'){
		if(l=='C'){
			cout<<"10";
			return 0;
		}
	}
	if(l=='A'){
		if(e=='C'){
			cout<<"10";
			return 0;
		}
	}
	cout<<"11";
	return 0;
} 
