#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string b,d,e,f,g,h,l,m;
	int a,c;
	cin>>a>>b>>c>>d;
	if(a != c){
		cout<<"0000";
	}
	else{
		e = b[0] + b[1];
		f = d[0] + d[1];
		if(e != f){
			cout<<"1000";
		}
		else{
			g = b[2];
			l = g;
			h = d[2];
			m = h;
			if(g == "E"&&g == "D"){
				g = "3";
			}
			if(h == "E"&&h == "D"){
				h = "3";
			}
			if(g != "E"&&g != "D"){
				g = "4";
			}
			if(h != "E"&&h != "D"){
				h = "4";
			}
			if(h != g){
				cout<<"1100";
			}
			else{
				if(h == "3" && g == "3"){
					cout<<"1111";
				}
				else{
					if(l != "B" && m != "B"){
						cout<<"1110";
					}
					else{
						cout<<"1111";
					}
				}
			}
		}
	}
}
