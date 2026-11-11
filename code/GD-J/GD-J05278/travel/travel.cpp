#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	char cc1=s1[2],cc2=s2[2];
	int k1=cc1-'A',k2=cc2-'A';
	if(k1<3 && k2<3){
		cout<<1;
	}else if(k1>=3 && k2>=3){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(k1==3||k2==3){
		if(k1==5||k2==5){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if((max(k1,k2)-min(k1,k2))==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
