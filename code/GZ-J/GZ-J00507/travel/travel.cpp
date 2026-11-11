//GZ-J00507 陈俊瑞 兴义市弘毅中学
#include<iostream>
#include<string>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string st1,st2;
	char ch1,ch2;
	cin>>c1>>s1>>c2>>s2;
	st1=s1[0]+s1[1];
	st2=s2[0]+s2[1];
	ch1=s1[2],ch2=s2[2];
	bool t1=0,t2=0,t3=0,t4=0;
	if(c1==c2){
		t1=1;
		if(st1==st2){
			t2=1;
			if((ch1<='C'&&ch2<='C')||ch1>='D'&&ch2>='D'){
				t3=1;
				if(ch1==ch2+1||ch1==ch2-1){
					t4=1;
				}
			}
		}
	}
	if(t1==1)cout<<1;
	else cout<<0;
	if(t2==1)cout<<1;
	else cout<<0;
	if(t3==1)cout<<1;
	else cout<<0;
	if(t4==1)cout<<1;
	else cout<<0;
	cout<<'\n';
	return 0;
}
