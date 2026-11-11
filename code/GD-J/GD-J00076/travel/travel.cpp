#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string w1,w2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>w1>>c2>>w2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	int wa=(w1[0]-'0')*10+w1[1],wb=(w2[0]-'0')*10+w2[1];
	if(wa==wb) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	char waa=w1[2],wbb=w2[2];
	int a=0,b=0;
	if(waa>='A'&&waa<='C') a=1;
	if(wbb>='A'&&wbb<='C') b=1;
	if(a==b) cout<<"1";
	else {
		cout<<"00";
		return 0;
	}
	int wa1=w1[2]-'A',wb1=w2[2]-'A';
	if(abs(wa1-wb1)==1) cout<<"1";
	else cout<<"0";
	return 0;
} 
