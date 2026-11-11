#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i1,i2;
	string a1,a2;
	cin>>i1>>a1>>i2>>a2;
	if(i1==i2){
		cout<<'1';
		if(a1[0]==a2[0]&&a1[1]==a2[1]){
			cout<<'1';
			bool w=(a1[2]=='A'||a1[2]=='B'||a1[2]=='C'&&a2[2]=='A'||a2[2]=='B'||a2[2]=='C');
			w=w||(a1[2]=='F'||a1[2]=='D'&&a2[2]=='F'||a1[2]=='D');
			if(w){
				cout<<1;
				if(a2[2]-a1[2]==-1||a2[2]-a1[2]==1){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000"<<endl;
		}
	}else{
		cout<<"0000"<<endl;
	}
	return 0;
}
