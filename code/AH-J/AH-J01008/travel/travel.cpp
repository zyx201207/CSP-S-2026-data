#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool fun(string s1,string s2){
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C') return 1;
	else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')) return 1;
	else return 0;
} 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	ll cnt=0,a=ll(s1[2]),b=ll(s2[2]);
	
	if(c1==c2){
		cout<<1;
		cnt++;
	}
	else cout<<0;
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&cnt==1){
		cout<<1;
		cnt++;
	}
	else cout<<0;
	
	if(fun(s1,s2)&&cnt==2){
		cout<<1;
		cnt++;
	}
	else cout<<0;
	
	if(abs(a-b)==1&&cnt==3){
		cout<<1;
		cnt++;
	}
	else cout<<0;

	return 0;
}
