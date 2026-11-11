#include<bits/stdc++.h>
using namespace std;
string s1,d1,s2,d2;
char a,b,c,d,e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>d1>>s2>>d2;
	if(s1==s2)//是否在同一节车厢
	{
		cout<<1;
		a=d1[0],b=d1[1],c=d1[2];
		d=d2[0],e=d2[1],f=d2[2];
		if(a==d&&b==e){//是否在同一节车厢的同一排
			cout<<1;
			if(c>='A'&&c<='C'){
				if(f>='A'&&f<='C'){//是否在同一节车厢的同一排，且位于过道的同一侧
					cout<<1;
					if(c=='A'&&f=='B'||c=='B'&&f=='A'||c=='B'&&f=='C'||c=='C'&&f=='B'){
						cout<<1;
					}
					else cout<<0;
				}
				else{
					cout<<0<<0;
				}
			}
			else if(c>='D'&&c<='E'){
				if(f>='D'&&f<='E'){//是否在同一节车厢的同一排，且位于过道的同一侧
					cout<<1;
					if(c=='D'&&f=='E'||c=='E'&&f=='D'){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<0<<0;
				}
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
