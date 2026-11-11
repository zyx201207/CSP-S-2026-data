#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin(x) freopen(x".in","r",stdin);
#define fop(x) freopen(x".out","w",stdout);
#define IO(x) fin(x)fop(x)
char a[3],b[3],a2[5],b2[5];
int main(){
	IO("travel")
	cin>>a;
	cin>>a2;
	cin>>b;
	cin>>b2;
	int m=0,n=0,p=0,q=0;
	for(int i=0;i<2;i++){
		m*=10;
		m+=a[i]-'0';
		n*=10;
		n+=b[i]-'0';
		p*=10;
		p+=a2[i]-'0';
		q*=10;
		q+=b2[i]-'0';
	}
	if(n!=m){
		cout<<"0000";
		return 0;
	}else if(p!=q){
		cout<<"1000";
		return 0;
	}else if(a2[2]-'A'<3&&b2[2]-'A'>=3){
		cout<<"1100";
		return 0;
	}else if(b2[2]-'A'<3&&a2[2]-'A'>=3){
		cout<<"1100";
		return 0;
	}else if(abs((a2[2]-'A')-(b2[2]-'A'))==1){
		cout<<"1111";
		return 0;
	}else if(a2[2]=='F'&&b2[2]=='D'){
		cout<<"1111";
		return 0;
	}else {
		cout<<"1110";
		return 0;
	}
	return 0;
}
