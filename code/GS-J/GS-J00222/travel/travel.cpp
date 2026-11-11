#include <bits/stdc++.h>
using namespace std;
string b,d;
int a,c;
bool f1=0,f2=0,f3=0,f4=0;
char s3,s4;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>a >>b >>c >>d;
	if (a==c){
		f1=1;
		int l1=b.size(),l2=d.size();
		string s1="",s2="";
		for (int i=0 ; i<l1-1 ; i++)
			s1+=b[i];
		for (int i=0 ; i<l2-1 ; i++)
			s2+=d[i];
		if (s1==s2){
			f2=1;
			s3+=b[l1-1];
			s4+=d[l1-1];
			if (s3<='c'&&s4<='c'||s3>='d'&&s4>='d'){
				f3=1;
				if (s3+1==s4||s4+1==s3) f4=1;
			}
		}
	}
	cout <<f1 <<f2 <<f3 <<f4;
	return 0;
}
