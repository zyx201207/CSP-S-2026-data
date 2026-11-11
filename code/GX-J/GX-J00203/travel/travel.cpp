#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	bool a=false,b=false,c=false,d=false;
	if(a1==b1){
		a=true;
		if(a2[0]==b2[0] && a2[1]==b2[1]){
			b=true;
			char ac=a2[2],bc=b2[2];
			unordered_map<char,int> m;
			m['A']=1,m['B']=1,m['C']=1,m['D']=2,m['F']=2;
			if(m[ac]==m[bc]){
				c=true;
				if(m[ac]==2){
					d=true;
				}
				else{
					if(ac=='A'){
						if(bc=='B') d=true;
					}else if(ac=='B'){
						d=true;
					}else{
						if(bc=='B') d=true;
					}
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
}
