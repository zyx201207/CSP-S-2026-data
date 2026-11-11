#include<bits/stdc++.h>
using namespace std;
void pts100(){
	string sa,sx,sb,sy;
	cin>>sa>>sx>>sb>>sy;
	if(sa!=sb){
		cout<<"0000";return;
	}else{
		cout<<"1";
		string a,b;a=sx,b=sy;
		a[2]='\0',b[2]='\0';
		if(a!=b){
			cout<<"000";return;
		}else{
			cout<<"1";
			char c,d;c=sx[2],d=sy[2];
			if(c=='A'||c=='B'||c=='C'){
				if(d=='A'||d=='B'||d=='C'){
					cout<<"1";
				}else{
					cout<<"00";return;
				}
			}else{
				if(d=='D'||d=='F'){
					cout<<"1";
				}else{
					cout<<"00";return;
				}
			}
			if(abs(c-d)==1){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	pts100();
	return 0;
}
