#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
string s1,s2;
string e="ABC DF";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) cout<<1;
	else{
		cout<<"0000";
		return 0;
	} 
	s1=a2.substr(0,2);
	a2.erase(0,2);
	s2=b2.substr(0,2);
	b2.erase(0,2);
	char g1=a2[0],g2=b2[0];
	if(s1==s2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	int c1,c2;
	for(int i=0;i<=5;i++){
		if(g1==e[i]) c1=i;
		if(g2==e[i]) c2=i;
	}
	if(c1<=2&&c2<=2||c1>=4&&c2>=4) cout<<1;
	else{
		cout<<"00";
		return 0;
	} 
	if(abs(c1-c2)==1) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}