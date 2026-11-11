#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool A=0,B=0,C=0,D=0;
	int x,y;
	x=(c1[0]-'0')*10+c1[1]-'0';
	y=(c2[0]-'0')*10+c2[1]-'0';
	int a,b;
	a=(s1[0]-'0')*10+s1[1]-'0';
	b=(s2[0]-'0')*10+s2[1]-'0';
	int p,q;
	p=s1[2]-'A'+1;
	q=s2[2]-'A'+1; 
	if(x==y){
		A=1;
		if(a==b){
			B=1;
			if((p<=3 && q<=3) || (p>3 && q>3)){
				C=1;
				if(abs(p-q)==1 || (s1[2]=='D' && s1[2]=='F') || (s1[2]=='F' && s1[2]=='D')){
					D=1;
				}else{
					D=0;
				}
			}else{
				C=0;
				D=0;
			}
		}else{
			B=0;
			C=0;
			D=0;
		}
	}else{
		A=0;
		B=0;
		C=0;
		D=0;
	}
	cout<<A<<B<<C<<D;
	return 0;
}
