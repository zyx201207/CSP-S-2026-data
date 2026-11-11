#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	char x1,x2;
	cin>>c1>>s1>>x1>>c2>>s2>>x2;
	if(c1 == c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1 == s2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((x1 >= 'A' && x1 <= 'C') && (x2 >= 'A' && x2 <= 'C')) cout<<1;
	else{
		if((x1 == 'D' || x1 == 'F') && (x2 == 'D' || x2 == 'F')) cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	if(int(x1) + 1 == int(x2) || int(x1) - 1 == int(x2)) cout<<1;
	else cout<<0;
	return 0;
}
