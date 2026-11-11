#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool d1=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<=1;i++){
		if(b[i]!=d[i]){
			d1=1;
			break;
		}
	}
	if(d1==1){
		cout<<"000";
		return 0;
	}
	else cout<<1;
	if((b[2]>'C'&&d[2]>'C')||(b[2]<'D'&&d[2]<'D')){
		cout<<1;
		if(b[2]==d[2]+1||b[2]==d[2]-1)cout<<1;
		else cout<<0;
	}
	else cout<<"00";
	return 0;
}

