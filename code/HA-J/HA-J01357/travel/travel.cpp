#include<bits/stdc++.h>
using namespace std;
string p1,p2,s1,s2;
bool a,b,c,d;
bool tip(){
	char a1 = s1[0],a2 = s1[1],b1 = s2[0],b2 = s2[1];
	return a1 == b1 && a2 == b2;
}
bool tiz(){
	char c1 = s1[2];
	char c2 = s2[2];
	if((c1 == 'A' || c1 == 'B' || c1 == 'C')&&(c2 == 'A' || c2 == 'B' || c2 == 'C')){
		return true;
	}else if((c1 == 'D' || c1 == 'E')&&(c2 == 'D' || c2 == 'E')){
		return false;
	}else{
		return false;
	}
}
int main(){
	cin.tie();
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> p1 >> s1 >> p2 >> s2;
	a = (p1 == p2);
	if(!a){
		b = c = d = a;
	}else{
		if(tip()){
			b = true;
			if(tiz()){
				c = true;
				char c1 = s1[2];
				char c2 = s2[2];
				if(abs((c1 - 'A') - (c2 - 'A')) == 1){
					d = true;
				}
			}
		}
	}
	cout << a << b << c << d;
	return 0;
}
