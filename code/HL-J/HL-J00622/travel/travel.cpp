#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char z,z1;
	cin>>c1>>s1>>z>>c2>>s2>>z1;
	if(c1 == c2){
		if(s1 == s2){
			if(((z=='A' || z=='B' || z=='C') && (z1=='A' || z1=='B' || z1=='C')) || ((z=='D' || z=='F') && (z1=='D' || z1=='F'))){
				if(((z=='D' || z=='F') && (z1=='D' || z1=='F')) || (abs(z1 - z) == 1)) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
    return 0;
}
