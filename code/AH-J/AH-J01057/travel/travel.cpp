#include <bits/stdc++.h>
using namespace std;
int ja,jb,ha,hb,ca,cb;
string x,y;
bool pd(char ch){
	return (ch=='A'||ch=='B'||ch=='C');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ja>>x>>jb>>y;
	ha=(x[0]-'0')*10+x[1]-'0';
	hb=(y[0]-'0')*10+y[1]-'0';
	ca=pd(x[2]);
	cb=pd(y[2]);
	if(ja==jb) {
		cout<<1;
		if(ha==hb){
			cout<<1;
			if(ca==cb){
				cout<<1;
				if(ca==1){
					if((x[2]-y[2])==1||(x[2]-y[2])==-1)
						cout<<1;
					else
						cout<<0;
				}
				else{
					cout<<1;
				}
			}
			else{
				cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	
	return 0;
}
