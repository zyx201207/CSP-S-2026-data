#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else if(c1!=c2){
		cout<<0;
	}
	int z1,z2,p1,p2;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			z1=z1*10+s1[i]-'0';
		}
		if(s1[i]>='A'&&s1[i]<='Z'){
			p1++;
		}
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			z2=z2*10+s2[i]-'0';
		}
		if(s2[i]>='A'&&s2[i]<='Z'){
			p2++;
		}
	}
	if(p1==p2){
		cout<<1;
	}
	else if(p1!=p2){
		cout<<0;
	}
	return 0;
}
