#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c,s;
	int a[3],x[3];
	char b[3];
	
	for(int i=0;i<2;i++){
		cin>>c>>s;
		a[i]=(c[0]-'0')*10+(c[1]-'0');
		x[i]=(s[0]-'0')*10+(s[1]-'0');
		b[i]=s[2];
	}
	
	if(a[0]==a[1]){
		cout<<1;
		if(x[0]==x[1]){
			 cout<<1;
			 if(((b[0]=='A')||(b[0]=='B')||(b[0]=='C'))&&((b[1]=='A')||(b[1]=='B')||(b[1]=='C'))){
			 	cout<<1;
			 	if(((b[0]=='A')||(b[0]=='B'))&&((b[1]=='A')||(b[1]=='B'))){
					cout<<1;
				}else if(((b[0]=='B')||(b[0]=='C'))&&((b[1]=='B')||(b[1]=='C'))){
					cout<<1;
				}else{
					cout<<0;
				}
			 }else if(((b[0]=='D')||(b[0]=='F'))&&((b[1]=='D')||(b[1]=='F'))){
			 		cout<<1<<1;
			 }else{
			 	cout<<0<<0;
			 }
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
