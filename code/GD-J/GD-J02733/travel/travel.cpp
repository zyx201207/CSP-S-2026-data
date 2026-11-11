#include<bits/stdc++.h>

using namespace std;

string c1,s1,c2,s2;

bool jud(){
	char c3=s1[2],c4=s2[2];
	bool f3=0,f4=0;
	if (c3=='A'||c3=='B'||c3=='C')f3=1;
	if (c4=='A'||c4=='B'||c4=='C')f4=1;
	return f3==f4;
}

int s2n(string s){
	int sum=0,c=10;
	for (int i=0;i<2;i++){
		sum+=(s[i]-'0')*c;
		c/=10;
	}
	return sum;
}


void che1(){
	if (c1==c2){
		cout<<1;
		int r1=s2n(s1),r2=s2n(s2);
		if (r1==r2){
			cout<<1;
			if (jud()){
				cout<<1;
				if (abs((int)s1[2]-(int)s2[2])==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00"; 
		}
		else {
			cout<<"000";
		}
	}
	else {
		cout<<"0000";
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	che1();
	return 0;
} 
