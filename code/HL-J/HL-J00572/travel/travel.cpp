#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char s1,s2;
	cin>>a>>b>>s1>>c>>d>>s2;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
		else if(b!=d){
			cout<<"1000";
			return 0;
			
		}
		else if(!(s1<='C'&&s2<='C')&&!(s1>'C'&&s2>'C')){
		cout<<"1100";
		return 0;
	}
	else if(!(s1-s2==1)&&!(s2-s1==1)){
		cout<<"1110";
		return 0;
	}
	else{
		cout<<"1111";
		return 0;
	}
	
	
}
