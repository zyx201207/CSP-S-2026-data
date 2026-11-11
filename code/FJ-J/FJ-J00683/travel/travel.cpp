#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2,g1,g2;char ch1,ch2;
bool lt(char ch){
	if(ch=='A'||ch=='B'||ch=='C')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>ch1>>c2>>s2>>ch2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1!=s2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(lt(ch1)!=lt(ch2)){
		cout<<"00";
		return 0;
	}
	cout<<1;
	cout<<(abs(ch1-ch2)==1);
	return 0;
}
