#include<bits/stdc++.h>
using namespace std;
string e,f;
char t,ce;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<'1';
		for(int i=0;i<b.size();i++){
			if(b[i]<='9'&&b[i]>='0'){
				e+=b[i];
			}
		} 
		for(int i=0;i<d.size();i++){
			if(d[i]<='9'&&d[i]>='0'){
				f+=d[i];
			}
		}
		if(e==f){
			cout<<'1';
			for(int i=0;i<b.size();i++){
				if(b[i]>='A'&&b[i]<='Z'){
					t=b[i];
				}
			} 
			for(int i=0;i<d.size();i++){
				if(d[i]>='A'&&d[i]<='Z'){
					ce=d[i];
				}
			} 
			if((t=='A'&&ce=='B')||(t=='A'&&ce=='C')||(t=='B'&&ce=='C')||(ce=='A'&&t=='B')||(ce=='A'&&t=='C')||(ce=='B'&&t=='C')||(t=='D'&&ce=='F')||(t=='F'&&ce=='D')){
				cout<<'1';
				if((t=='A'&&ce=='B')||(t=='B'&&ce=='C')||(t=='D'&&ce=='F')||(t=='B'&&ce=='A')||(t=='C'&&ce=='B')||(t=='F'&&ce=='D')){
					cout<<'1';
				}
				else cout<<'0';
			}
			else cout<<"00";
		}
		else{
			cout<<"000";
		}
	}
	else cout<<"0000";
	return 0;
}
