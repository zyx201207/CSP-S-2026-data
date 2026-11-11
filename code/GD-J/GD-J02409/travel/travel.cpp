#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		string tb=b.substr(0,2);
		string td=d.substr(0,2);
		if(tb==td){
			cout<<1;
			int bb=(int)b[2],dd=(int)d[2];
			if((bb<=67&&dd>67) || bb>67&&dd<=67) cout<<"00";
			else{
				cout<<1;
				if((bb==70&&dd==68) || (bb==68&&dd==70)) cout<<1;
				else if(abs(bb-dd)==1) cout<<1;
				else cout<<0;
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
