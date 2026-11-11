#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int k=0,l=0;
	char n,m;
	string s;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=0;i<3;i++){
		if(b[i]<='Z'&&b[i]>='A'){
				n=b[i];
			}
		if(d[i]<='Z'&&d[i]>='A'){
			m=d[i];
			}
		}
		for(int i=0;i<2;i++){
				if(b[i]<='9'&&b[i]>='0') {
					k+=int(b[i]);	
				}
				if(d[i]<='9'&&d[i]>='0') {
					l+=int(d[i]);	
				}
				
			}
	if(a==c) cout<<1;
	else{
		 cout<<"0000";
		 return 0;
	 }
	if(k==l) cout<<1;
	else {
		cout<<"000";
		return 0;
		}
	if(n<='C'&&m<='C') s="1";
	else if(n>='D'&&m>='D') s="1";
	else{ 
		s="00";
	cout<<s;
	return 0;
}
	if(n=='D'&&m=='F') {
		cout<<1;
		return 0;
		}
	if(n=='F'&&m=='D'){ 
		cout<<1;
		return 0;
		}
	 if(n=='C'&&m=='D'){
		cout<<"00";
		return 0;
		}
		 if(n=='D'&&m=='C'){
		cout<<"00";
		return 0;
		}
	if(int(n)==int(m)+1||int (n)==int (m)-1) cout<<1;
	else cout<<0;
	return 0;
}
