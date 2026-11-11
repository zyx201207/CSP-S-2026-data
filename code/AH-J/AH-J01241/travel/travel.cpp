#include<bits/stdc++.h>
using namespace std;
int main(){
	//abc df
	//012 35
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1!=c3)cout<<"0000";
	else{
		cout<<"1";
		string l1,l2;
		l1=c2[0]+c2[1];
		l2=c4[0]+c4[1];
		if(l1!=l2)cout<<"000";
		else{
			cout<<"1";
			int a,b;
			a=c2[2]-65;
			b=c4[2]-65;
			if(a<=2&&b<=2||a>=3&&b>=3){
				cout<<"1";
				if(abs(a-b)==1&&a!=3&&b!=3||a==3&&b==5||a==5&&b==3)cout<<"1";
				else cout<<"0";
			}else{
				cout<<"00";
			}
		}
	}
	return 0;
}
