#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("traval.in","r",stdin);
	freopen("traval.ans","w",stdout);
	long long c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	//cout<<c1<<s1<<endl<<c2<<s2;
	int a=s1[0],b=s1[1],x=s1[2],c=s2[0],d=s2[1],x2=s2[2];
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	//cout<<x<<" "<<x2<<endl;
	if(c1==c2){
		cout<<"1";
		if(a*10+b==c*10+d){
			cout<<"1";
			if((x<'D'&&x2<'D')||(x>='D'&&x2>='D')){
				cout<<"1";
				if((x=='A'&&x2=='B')||(x=='B'&&x2=='A')||(x=='B'&&x2=='C')||(x=='C'&&x2=='B')||(x2=='A'&&x=='B')||(x2=='B'&&x=='A')||(x2=='B'&&x=='C')||(x2=='C'&&x=='B')||(x=='D'&&x2=='E')||(x=='E'&&x2=='D')||(x2=='D'&&x=='E')||(x2=='E'&&x=='D')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
