#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1=0,a2=0,b1=0,b2=0;
	char d1,d2;
	string  c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<c1.size();i++){
		a1=a1+(c1[i]-'0')*pow(10,2-i);
	}
	for(int i=1;i<c2.size();i++){
		a2=a2+(c2[i]-'0')*pow(10,2-i);
	}
	if(a1==a2)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	for(int i=1;i<s1.size();i++){
		if(s1[i]>='0' && s1[i]<='9')b1=b1+(s1[i]-'0')*pow(10,2-i);
		else{
			d1=s1[i];
		}
	}
	for(int i=1;i<s2.size();i++){
		if(s2[i]>='0' && s2[i]<='9')b2=b2+(s2[i]-'0')*pow(10,2-i);
		else{
			d2=s2[i];
		}
	}
	if(b1==b2)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(abs(d1-d2)<=2){
		if(d1=='C' && d2=='D' || d1=='D' && d2=='C') {
			cout<<"00";
			return 0;
		}
		else cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(d1-d2)==1) cout<<1;
	else cout<<0;
	return 0;
}
