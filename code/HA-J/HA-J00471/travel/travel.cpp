#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cn,cm,an,am;
	string sn,sm;
	char q,w;
	cin>>cn>>sn>>cm>>sm;
	an=int(sn[0]-'0')*10+int(sn[1]-'0');
	q=sn[2];
	am=int(sm[0]-'0')*10+int(sm[1]-'0');
	w=sm[2];
	if(cn==cm){	
		cout<<1;
		if(an==am){
			cout<<1;
			if((q<='C'&&w<='C')||(q>='D'&&w>='D')){
				cout<<1;
				if(int(q)-int(w)==1||int(q)-int(w)==-1) cout<<1;
				else cout<<0<<"\n";
			}
			else cout<<0<<0<<"\n";
		}
		else{
			cout<<0<<0<<0<<"\n";
		}
	}
	else{
		cout<<0<<0<<0<<0<<"\n";
	}
	return 0;
} 
