#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long a1,c1,b1,d1;
int p[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<(int)a.size();i++){
		a1=a1*10+a[i]-'0';
	}
	for(int i=0;i<(int)c.size();i++){
		c1=c1*10+c[i]-'0';
	}
	if(a1==c1){
		cout<<"1";
		for(int i=0;i<2;i++){
			b1=b1*10+b[i]-'0';
		}
		for(int i=0;i<2;i++){
			d1=d1*10+d[i]-'0';
		}
		if(b1==d1){
			cout<<"1";
			char c2,c3;
			c2=b[2];
			c3=d[2];
			if((c2=='A'&&c3=='B')||(c2=='B'&&c3=='C')||(c2=='A'&&c3=='C')||(c3=='A'&&c2=='B')||(c3=='B'&&c2=='C')||(c3=='A'&&c2=='C')||(c2=='D'&&c3=='F')||(c2=='F'&&c3=='D')){
				cout<<"1";
				if(((c2-c3==1||c3-c2==1)&&b1==d1)||(c2==c3&&(b1-d1==1||d1-b1==1))){
					if((c2=='C'&&c3=='D')||(c2=='D'&&c3=='C')){
						cout<<"0";
					}
					else cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
