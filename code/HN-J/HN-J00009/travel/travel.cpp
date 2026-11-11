#include<bits/stdc++.h>
using namespace std;
char a[3],a1[3],b[5],b1[5];
bool cb=0,S=0;
bool next(){
	if((b[0]==b1[0]&&b[1]==b1[1])&&((b[2]<='C'&&b[2]>='A'&&b1[2]<='C'&&b1[2]>='A')||(b[2]<='E'&&b[2]>='D'&&b1[2]<='E'&&b1[2]>='D'))){
		cb=1;
	}
	if(cb&&(b[2]-1==b1[2]||b[2]+1==b1[2])){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>a1>>b1;
	int T=0;
	for(int i=0;i<=2;i++){
		if(a[i]==a1[i]){
			T++;
		}
	}
	if(T!=3){
		cout<<0<<0<<0<<next();
		return 0;
	}
	cout<<1;
	if(b[0]==b1[0]&&b[1]==b1[1]){
		cout<<1;
		S=1;
	}else{
		cout<<0;
	}
	if(S&&(b[2]<='C'&&b[2]>='A'&&b1[2]<='C'&&b1[2]>='A')||(b[2]<='E'&&b[2]>='D'&&b1[2]<='E'&&b1[2]>='D')){
		cout<<1;
	}else{
		cout<<0;
	}
	cout<<next();
	return 0;
}

