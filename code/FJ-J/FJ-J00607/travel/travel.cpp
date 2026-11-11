#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char w1,w2;
int p1,p2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	w1=s1[2],w2=s2[2];
	p1=(s1[0]-'0')*10+(s1[1]-'0');
	p2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2){
		cout<<1;
		if(p1==p2){
			cout<<1;
			if(w1<='C'&&w2<='C'||w1>'C'&&w2>'C'){
				cout<<1;
				if(w1>'C'&&w2>'C'){
					if(w1!=w2){
						cout<<1;
					}else{
						cout<<0;
					}
				}else{
					if(w1-w2==1||w2-w1==1){
						cout<<1;
					}else{
						cout<<0;
					}
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
