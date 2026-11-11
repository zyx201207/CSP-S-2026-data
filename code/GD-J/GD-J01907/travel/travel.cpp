#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			int a1=b[2]-'A';
			int a2=d[2]-'A';
			if(b[2]-'A'>d[2]-'A'){
				swap(a1,a2);
			}
			if(a1==0&&a2==1||a1==1&&a2==2||a1==3&&a2==5){
				cout<<"11";
			}
			else if(a1<=2&&a2>2){
				cout<<"00";
			}
			else{
				cout<<"10";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
