#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]>=65&&b[2]<=67&&d[2]>=65&&d[2]<=67){
		cout<<1;
		if((b[2]==65&&d[2]==66)||(b[2]==66&&d[2]==65)||(b[2]==66&&d[2]==67)||(b[2]==67&&d[2]==66)){
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else if((b[2]==68||b[2]==70)&&(d[2]==68||d[2]==70)){
		cout<<11;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	return 0;
} 
