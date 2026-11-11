#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int cnt=0;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
		cnt++;
		if(b[0]==d[0]&&d[1]==b[1]){
			cout<<1;
			cnt++;
			if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]='C'&&d[2]=='A')||(b[2]=='A'&&d[2]=='C')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
				cout<<1;
				cnt++;
				if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
					cout<<1;
					cnt++;
				}
			}
		}
	}
	for(int i=1;i<=4-cnt;i++){
		cout<<0;
	}
	return 0;
}

