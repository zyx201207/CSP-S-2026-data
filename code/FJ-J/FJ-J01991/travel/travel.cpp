#include<bits/stdc++.h>
using namespace std;
string c,s,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>s>>x>>y;
	if(c!=x){
		cout<<"0000";
		exit(0);
	}
	else {
		cout<<1;
		for(int i=0;i<2;i++){
			if(s[i]!=y[i]){
				cout<<"000";
				exit(0);
			}
		}
		cout<<1;
		if((s[2]<'D'&&y[2]<'D')||(s[2]>'C'&&y[2]>'C'))cout<<1;
		else {
			cout<<"00";
			exit(0);
		}
		char m,n;
		m=s[2];
		n=y[2];
		int cp=(int)m;
		int cq=(int)n;
		if(abs(cp-cq)==1)cout<<1;
		else cout<<0;
	}
	return 0;
}
