#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::string a1,s2,b1,d2;
	std::cin>>a1>>s2>>b1>>d2;
	int z=0,x=0,c=0,v=0;
	int a=int(a1[0])*10+int(a1[1]);
	int b=int(b1[0])*10+int(b1[1]);
	int q;
	if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
		q=1;
	}
	else{
		q=0;
	}
	int e;
	if(d2[2]=='A' || d2[2]=='B' || d2[2]=='C'){
		e=1;
	}
	else{
		e=0;
	}
	if(a!=b){
		std::cout<<z<<x<<c<<v;
		return 0;
	}
	else{
	}
		z=1;
		int pa=int(s2[0])*10+int(s2[1]);
		int pb=int(d2[0])*10+int(d2[1]);
		if(pa!=pb){
			std::cout<<z<<x<<c<<v;
			return 0;
		}
		else{
			x=1;
			if(q!=e){
				std::cout<<z<<x<<c<<v;
				return 0;
			}
			else{
				c=1;
				if(q==1){
					if(s2[2]=='A' && d2[2]=='C'){
						std::cout<<z<<x<<c<<v;
						return 0;
					}
					else if(s2[2]=='C' && d2[2]=='A'){
						std::cout<<z<<x<<c<<v;
						return 0;
					}
				else{
					v=1;
				}
			}
		}
	}
	cout<<z<<x<<c<<v;
	return 0;
}
