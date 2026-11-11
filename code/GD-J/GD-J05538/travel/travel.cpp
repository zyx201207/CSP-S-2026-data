#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;int p,p2,p3,p4,k,l,k2,l2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		p=1;
	}
	k=(a2[0]-'0')*10+(a2[1]-'0');
	l=(b2[0]-'0')*10+(b2[1]-'0');
	if(p==1&&k==l){
		p2=1;
	}
	k2=a2[2]-'A'+1;
	l2=b2[2]-'A'+1;
	if(p2==1&&p==1&&((k2>=4&&l2>=4)||(k2<=3&&l2<=3))){
		p3=1;
	}
	if(p3==1&&p2==1&&p==1&&abs(k2-l2)==1){
		p4=1;
	}
	cout<<p<<p2<<p3<<p4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
