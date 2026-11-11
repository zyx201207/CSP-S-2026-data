#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool f1=0,f2=0,f3=0,f4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		f1=1;
	}else{
		cout<<f1<<f2<<f3<<f4;
		return 0;
	}
	int t1=b[0],t2=b[1],u1=d[0],u2=d[1];
	char t3=b[2],u3=d[2];
	if(t1==u1&&t2==u2){
		f2=1;
	}
	else{
		cout<<f1<<f2<<f3<<f4;
		return 0;
	}
	if((t3=='A'&&(u3=='B'||u3=='C'))||(t3=='B'&&(u3=='A'||u3=='C'))||(t3=='C'&&(u3=='A'||u3=='A'))||(t3=='D'&&u3=='F')||t3=='F'&&u3=='D'){
		f3=1;
	}else{
		cout<<f1<<f2<<f3<<f4;
		return 0;
	}
	if(t3=='A'&&u3=='B'||t3=='B'&&u3=='A'||t3=='B'&&u3=='C'||t3=='C'&&u3=='B'||t3=='D'&&u3=='F'||t3=='F'&&u3=='D'){
			f4=1;
	}else{
		cout<<f1<<f2<<f3<<f4;
		return 0;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
