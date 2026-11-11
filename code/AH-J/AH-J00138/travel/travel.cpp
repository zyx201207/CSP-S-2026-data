#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a1,a2;
string s1,s2;
bool f=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2) printf("1");
	else{
		printf("0");
		f=1;
	}
	string t1,t2;
	t1=s1[0]+s1[1];
	t2=s2[0]+s2[1];
	if(t1==t2 && !f) printf("1");
	else{
		printf("0");
		f=1;
	}
	if(!f && (s1[2]<='C' && s2[2]<='C') || (s2[2]>='D' && s1[2]>='D')) printf("1");
	else{
		printf("0");
		f=1;
	}
	if(f==1) printf("0");
	else printf("1");
	return 0;
}
