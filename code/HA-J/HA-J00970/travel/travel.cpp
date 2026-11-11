#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	bool f=true;
	string c1,s1,c2,s2,a,b;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else {cout<<0;f=false;}
	for(int i=0;i<s1.size()-1;i++){
		a=s1[i];
		b=s2[i];
	}
	if(a==b&&f==true) cout<<1;
	else {cout<<0;f=false;}
	int c,v;
	c=s1[2]-'A';
	v=s2[2]-'A';
	if(c<=2&&v<=2&&f==true) cout<<1;
	else if(c>2&&v>2&&f==true) cout<<1;
	else {cout<<0;f=false;}
	if(c-v!=1&&c-v!=-1){
		f=false;
	}
	if(f) cout<<1;
	else cout<<0;
	return 0;
}
