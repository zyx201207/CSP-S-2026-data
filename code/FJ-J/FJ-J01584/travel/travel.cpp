#include <bits/stdc++.h>
using namespace std;
const int N=1e3+1;
int c1,s1,c2,s2;
char a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>a1>>c2>>s2>>a2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(s1!=s2){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if((a1<='C'&&a2<='C')||(a1>='D'&&a2>='D')){
		cout<<"1";
		if(a1>a2) swap(a1,a2);
		if(a2-a1==1&&a2!='D'&&a1!='C') cout<<"1";
		else cout<<"0";
	}else{
		cout<<"00";
		return 0;
	}
	return 0;
}

