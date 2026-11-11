#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2,t,k;
char a,b;
bool n,m,p;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>c1>>c2;
	if (s1!=c1){
		n=1;
		cout<<0;
	}else{
		cout<<1;
	}
	t=s2[0]+s2[1];
	a=s2[2];
	k=c2[0]+c2[1];
	b=c2[2];
	if (t==k&&n==0){
		cout<<1;
	}else{
		m=1;
		cout<<0;
	}
	if (((a<='C'&&b<='C')||(a>='D'&&b>='D'))&&m==0){
		cout<<1;
	}else{
		p=1;
		cout<<0;
	}
	if (a<='C'&&b<='C'&&p==0){
		if (a+1==b||a-1==b){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if (((a=='D'&&b=='F')||(a=='F'&&b=='D'))&&p==0){
		cout<<1;
		return 0;
	}else{
		cout<<0;
		return 0;
	}
	return 0;
}
