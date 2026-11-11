#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[5];
	for(int i=0;i<4;i++){
		cin>>a[i];
	}
	string ans="0000";
	if(a[0]==a[2]){
		ans[0]='1';
	}
	string q=a[1],w=a[3];
	if(a[0]==a[2]){
		ans[1]='1';
	}
	if(q[2]=='A'&&w[2]=='B'||q[2]=='A'&&w[2]=='C'||q[2]=='B'&&w[2]=='A'||q[2]=='B'&&w[2]=='C'||q[2]=='C'&&w[2]=='A'||q[2]=='C'&&w[2]=='B'){
		ans[2]='1';
	}
	 if(q[2]=='D'&&w[2]=='F'||q[2]=='F'&&w[2]=='D'){
		ans[2]='1';
	}
	if(q[2]=='A'&&w[2]=='B'||q[2]=='B'&&w[2]=='A'||q[2]=='B'&&w[2]=='C'||q[2]=='C'&&w[2]=='B'||q[2]=='D'&&w[2]=='F'||q[2]=='F'&&w[2]=='D'){
		ans[3]='1';
	}
	cout<<ans<<endl;
	return 0;
}

