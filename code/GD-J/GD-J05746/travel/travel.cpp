#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//Trick||Treat!
	cin>>a>>b>>c>>d;
	b='@'+b,d='@'+d; 
	if(a!=c){
		cout<<"0000"; 
	}
	else{
		cout<<1;
		if(b[1]==d[1]&&b[2]==d[2]){
			cout<<1;
			if(int(b[3]-'A'+1)>3&&int(d[3]-'A'+1)>3||int(b[3]-'A'+1)<=3&&int(d[3]-'A'+1)<=3){
				cout<<1;
				if(max(int(b[3]),int(d[3]))-min(int(b[3]),int(d[3]))==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	return 0;
} 
