#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	char c[4],d[4],a[4],b[4];
	for(int i=1;i<=2;i++)cin>>a[i];
	for(int i=1;i<=3;i++)cin>>b[i];
	for(int i=1;i<=2;i++)cin>>c[i];
	for(int i=1;i<=3;i++)cin>>d[i];
	for(int i=1;i<=2;i++){
		if(a[i]!=c[i]){
			cout<<"0000";return 0;
		}
	}
	cout<<1;
	for(int i=1;i<=2;i++){
		if(b[i]!=d[i]){
			cout<<"000";return 0;
		}
	}
	cout<<1;
	if(b[3]=='A'&&d[3]=='B'){cout<<"11";return 0;}
	if(b[3]=='B'&&d[3]=='A'){cout<<"11";return 0;}
	if(b[3]=='A'&&d[3]=='C'){cout<<"10";return 0;}
	if(b[3]=='C'&&d[3]=='A'){cout<<"10";return 0;	}
	if(b[3]=='B'&&d[3]=='C'){cout<<"11";return 0;}
	if(b[3]=='C'&&d[3]=='B'){cout<<"11";return 0;	}
	if(b[3]=='A'&&d[3]!='B'&&d[3]!='C'){cout<<"00";return 0;}
	if(b[3]=='B'&&d[3]!='A'&&d[3]!='C'){cout<<"00";return 0;}
	if(b[3]=='C'&&d[3]!='B'&&d[3]!='A'){cout<<"00";return 0;}
	if(d[3]=='A'&&b[3]!='B'&&b[3]!='C'){cout<<"00";return 0;}
	if(d[3]=='B'&&b[3]!='A'&&b[3]!='C'){cout<<"00";return 0;}
	if(d[3]=='C'&&b[3]!='B'&&b[3]!='A'){cout<<"00";return 0;}
	if(b[3]=='F'&&d[3]=='D'){
		cout<<"11";return 0;
	}
	else{
		cout<<"00";return 0;
	}
	if(b[3]=='F'&&d[3]=='D'){
		cout<<"11";return 0;
	}
	else{
		cout<<"00";return 0;
	}
}
