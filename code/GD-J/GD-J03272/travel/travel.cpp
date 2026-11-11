#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int c3,c4;
	c3=(c1[0]-'0')*10;
	c3+=(c1[1]-'0');
	c4=(c2[0]-'0')*10;
	c4+=(c2[1]-'0');
	if(c3==c4){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	c3=(s1[0]-'0')*10;
	c3+=(s1[1]-'0');
	c4=(s2[0]-'0')*10;
	c4+=(s2[1]-'0');
	if(c3==c4){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	char s3,s4;
	s3=s1[2];
	s4=s2[2];
	if(s3=='A'){
		if(s4=='B'){
			cout<<1;
			cout<<1;
			return 0;
		}else if(s4=='D'||s4=='F'){
			cout<<0;
			cout<<0;
			return 0;
		}else if(s4=='C'){
			cout<<1;
			cout<<0;
			return 0;
		}
	}else if(s3=='B'){
		if(s4=='A'||s4=='C'){
			cout<<1;
			cout<<1;
			return 0;
		}else if(s4=='D'||s4=='F'){
			cout<<0;
			cout<<0;
			return 0;
		}
	}else if(s3=='C'){
		if(s4=='B'){
			cout<<1;
			cout<<1;
			return 0;
		}else if(s4=='D'||s4=='F'){
			cout<<0;
			cout<<0;
			return 0;
		}else if(s4=='A'){
			cout<<1;
			cout<<0;
			return 0;
		}
	}else if(s3=='D'){
		if(s4=='A'||s4=='C'||s4=='B'){
			cout<<0;
			cout<<0;
			return 0;
		}else if(s4=='F'){
			cout<<1;
			cout<<1;
			return 0;
		}
	}else if(s3=='F'){
		if(s4=='A'||s4=='C'||s4=='B'){
			cout<<0;
			cout<<0;
			return 0;
		}else if(s4=='D'){
			cout<<1;
			cout<<1;
			return 0;
		}
	}
	return 0;
}
