#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,a1,b1;
	char a2,b2;
	string c,d;
	cin>>a>>c>>b>>d;
	a1=c[0]*10+c[1];
	b1=d[0]*10+d[1];
	a2=c[2];b2=d[2];
	if(a2=='D')a2++;
	if(b2=='D')b2++;
	if(a==b){
		cout<<"1";
		if(a1==b1){
			cout<<"1";
			if(((a2=='A'||a2=='B'||a2=='C')&&(b2=='A'||b2=='B'||b2=='C'))||((a2=='E'||a2=='F')&&(b2=='E'||b2=='F'))){
				cout<<"1";
				if(abs(a2-b2)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}cout<<endl;
	return 0;
}
