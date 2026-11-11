#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a!=b){
		cout<<"0000";
		return 0;
	} 
	cout<<1;
	LL d1=(s1[0]-'0')*10+(s1[1]-'0');
	LL d2=(s2[0]-'0')*10+(s2[1]-'0');
	if(d1!=d2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	char c1=s1[2],c2=s2[2];
	if(!((c1<='C'&&c2<='C')||(c1>='D'&&c2>='D'))){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(c1>c2) swap(c1,c2);
	if(abs(c1-c2)!=1&&c1!='D'&&c2!='F'){
		cout<<"0";
		return 0;
	}
	cout<<1;
	return 0;
}
