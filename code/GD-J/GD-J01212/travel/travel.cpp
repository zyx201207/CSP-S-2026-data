#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";return 0;
	}
	for(int i=0;i<s1.size()-1;i++){
		a=a*10+s1[i]-'0';
		b=b*10+s2[i]-'0';
	}
	if(a!=b){
		cout<<"1000";return 0;
	}
	if(!(s1[2]-'C'<=0 && s2[2]-'C'<=0 || s1[2]-'C'>0 && s2[2]-'C'>0)){
		cout<<"1100";return 0;
	}
	if(abs(s1[2]-s2[2])>1){
		cout<<"1110";return 0;
	}
	cout<<"1111";
	return 0;
}
