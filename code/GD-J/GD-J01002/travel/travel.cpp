#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int a=0,b=0;
		for(int i=0;i<=1;i++){
			a=a*10+(s1[i]-'0');
			b=b*10+(s2[i]-'0');
		}
		if(a==b){
		cout<<1;
			a=s1[2]-'A';
			b=s2[2]-'A';
			if((a<=2&&b<=2)||(a>2&&b>a)){
				cout<<1;
				if(a+1==b||b+1==a) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
