#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	int a=0,b=0,c=1,d=1;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=1;
	}
	for(int i=1;i<2;i++){
		if(s1[i]==s2[i]){
			b=1;
		}
		else{
			b=0;
		}
	}
	if(b==0){
		c=0;
		d=0;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
