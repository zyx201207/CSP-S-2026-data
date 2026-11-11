#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n,m;
	string a,b,ap,bp;
	cin>>n>>a>>m>>b;
	ap=int(a[0]-'0')*10+int(a[1]-'0');
	bp=int(b[0]-'0')*10+int(b[1]-'0');
	if(n==m){
		cout<<1;
			if(ap==bp){
				cout<<1;
				if(int(a[2]-'A'+1)+int(b[2]-'A'+1)<9){
					cout<<1;
				if((a[2]=='A'&&b[2]=='C')||(b[2]=='A'&&a[2]=='C'))
					cout<<0;
				else
					cout<<1;
			}
				else if(int(a[2]-'A'+1)+int(b[2]-'A'+1)==9)
					cout<<"11";		
				else
					cout<<"00";
			}
			else
				cout<<"000";
		}
	else
		cout<<"0000";
	return 0;
} 
