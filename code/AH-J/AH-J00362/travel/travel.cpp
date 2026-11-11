#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000"<<'\n';
		return 0;
	}
	cout<<'1';
	if(b[0]!=d[0] || b[1]!=d[1]){
		cout<<"000"<<'\n';
		return 0;
	}
	cout<<'1';
	if(b[2]=='A'&&d[2]=='B'||d[2]=='A'&&b[2]=='B'){
		cout<<"11"<<'\n';
	}
	if(b[2]=='A'&&d[2]=='C'||d[2]=='A'&&b[2]=='C'){
		cout<<"10"<<'\n';
	}
	if(b[2]=='A'&&d[2]=='D'||d[2]=='A'&&b[2]=='D'){
		cout<<"00"<<'\n';
	}
	if(b[2]=='A'&&d[2]=='F'||d[2]=='A'&&b[2]=='F'){
		cout<<"00"<<'\n';
	}
	if(b[2]=='B'&&d[2]=='C'||d[2]=='B'&&b[2]=='C'){
		cout<<"11"<<'\n';
	}
	if(b[2]=='B'&&d[2]=='D'||d[2]=='B'&&b[2]=='D'){
		cout<<"00"<<'\n';
	}
	if(b[2]=='B'&&d[2]=='F'||d[2]=='B'&&b[2]=='F'){
		cout<<"00"<<'\n';
	}
	if(b[2]=='C'&&d[2]=='D'||d[2]=='C'&&b[2]=='D'){
		cout<<"00"<<'\n';
	}
	if(b[2]=='C'&&d[2]=='F'||d[2]=='C'&&b[2]=='F'){
		cout<<"00"<<'\n';
	}
	if(b[2]=='D'&&d[2]=='F'||d[2]=='D'&&b[2]=='F'){
		cout<<"11"<<'\n';
	}
	return 0;
}
