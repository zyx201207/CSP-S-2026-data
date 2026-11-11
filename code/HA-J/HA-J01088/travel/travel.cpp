#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int sa=(s1[0]-'0')*10+(s1[1]-'0'),sb=(s2[0]-'0')*10+(s2[1]-'0');
	if(sa==sb){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	int r=s1[2]-'A',x=s2[2]-'A';
	if(r+x==8){
		cout<<1<<1;
		return 0;
	}else if(r==3||r==5||x==3||x==5){
		cout<<0<<0;
		return 0;
	}else{
		cout<<1;
	}
	cout<<(abs(r-x)==1);
	return 0;
}
