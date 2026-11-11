#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			bool o=0,p=0;
			if(b[2]=='D'||b[2]=='F')o=1;
			if(d[2]=='D'||d[2]=='F')p=1;
			if(o==p){
				cout<<1;
				if(abs(int(b[2])-int(d[2]))==1)cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else {
		cout<<"0000";
	}
	cout<<endl;
}
