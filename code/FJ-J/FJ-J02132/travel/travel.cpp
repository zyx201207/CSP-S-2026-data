#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<"1";
		int a1=(s1[0]-'0')*10+s1[1]-'0';
		int a2=(s2[0]-'0')*10+s2[1]-'0';
		if(a1==a2){
			cout<<"1";
			int b1=s1[2]-'A';
			int b2=s2[2]-'A';
			if((b1<=2 && b2<=2) || (b1>2 && b1<=4 && b2>2 && b2<=4)){
				cout<<"1";
				if(abs(b2-b1)<=1){
					if((b1==2 && b2==3)  || (b1==3 && b2==2))
						cout<<"0";
					else cout<<"1";
				}
				
				else cout<<"0";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else cout<<"0000";
	return 0;
}
