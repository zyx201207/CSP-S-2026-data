#include<bits/stdc++.h>
#define ll long long
using namespace std;
int aa,ba;
string ab,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>aa>>ab>>ba>>bb;
	if(aa!=ba) cout<<"0000";
	else{
		cout<<"1";
		if(ab[0]!=bb[0] || ab[1]!=bb[1]) cout<<"000";
		else{
			cout<<"1";
			int ac=ab[2]-'A',bc=bb[2]-'A';
			if((ac<=2 && bc>2) || (ac<=2 && bc>2)) cout<<"00";
			else{
				cout<<"1";
				if(abs(ac-bc)==1) cout<<"1";
				else cout<<"0";
			}
		}
	}
	return 0;
}
