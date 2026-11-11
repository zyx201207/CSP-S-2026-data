#include<bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";return 0;
	}
	int nb=(b[0]-'0')*10+b[1]-'0',nd=(d[0]-'0')*10+d[1]-'0';
	if(nb!=nd){
		cout<<"1000";return 0;
	}
	nb=b[2]-'A'+1;nd=d[2]-'A'+1;
	bool fb=(nb<=3),fd=(nd<=3);
	if(fb!=fd){
		cout<<"1100";return 0;
	}
	if(nb-nd!=1&&nd-nb!=1){
		cout<<"1110";return 0;
	}
	cout<<"1111";
	return 0;
}
