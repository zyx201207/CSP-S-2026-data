#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,s2,s3;
	cin>>s>>s1>>s2>>s3;
	if(s!=s2){
		cout<<"0000";
		return 0;c
	}
	char a=s1[0],a1=s1[1],a2=s3[0],a3=s3[1],q=s1[2],p=s3[2];
	if(a!=a2||a1!=a3){
		cout<<"1000";
		return 0;
	}
	if(q=='F'&&p!='D'||q=='D'&&p!='F'||p=='F'&&q!='D'||p=='D'&&q!='F'){
		cout<<"1100";
		return 0;
	}
	if(q=='A'&&p=='C'||q=='C'&&p=='A'){
		cout<<"1110";
		return 0;
	}
	else cout<<"1111";
	return 0;
}
