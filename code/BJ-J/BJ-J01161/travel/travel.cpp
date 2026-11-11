#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1;
	string a2,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){
		cout<<0000;
		return 0;
	}
	if(a2[0]!=b2[0]||a2[1]!=b2[1]){
		cout<<1000;
		return 0;
	}
	char c1=a2[2],c2=b2[2];
	if((c1>='D'&&c2<'D')||(c1<'D'&&c2>='D')){
		cout<<1100;
		return 0;
	}
	if(c1-'0'-(c2-'0')==1||c1-'0'-(c2-'0')==-1){
		cout<<1111;
	}
	else{
		cout<<1110;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
