#include<bits/stdc++.h>
using namespace std;

string a,b,c,d,e,f;
int da,db,dc,dd;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b[1]>>b[2]>>c[1]>>d>>e[1]>>e[2]>>f[1];
	if(a==d){
		cout<<1;
		if(b[1]==e[1]&&b[2]==e[2]){
			cout<<1;
		}
		else {
			cout<<"000";
			return 0;
		}
		if((c[1]=='D'&&f[1]=='C')||(c[1]=='C'&&f[1]=='D')){
			cout<<"00";
			return 0;
		}
		else cout<<1;
		if((c[1]-f[1]==1)||(c[1]-f[1]==-1)){
			cout<<1;
			return 0;
		}
		else {
			cout<<0;
			return 0;
		}
	}
	else {
		cout<<"0000";
		return 0;
	}
	return 0;
}
