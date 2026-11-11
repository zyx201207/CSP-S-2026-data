#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel4.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int a,b;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	char A=s1[2],B=s2[2];
	string s=s1.substr(0,2),ss=s2.substr(0,2);
	int C=(s[0]-'0')*10+(s[1]-'0'),D=(ss[0]-'0')*10+(ss[1]-'0');
	if(a==b){
		if(C==D){
			bool x=(A<='C'&&B<='C'),y=(A>='D'&&B>='D');
			if(x||y){
				int n=A,m=B;
				if(abs(n-m)==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
