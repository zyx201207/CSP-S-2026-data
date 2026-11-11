#include<bits/stdc++.h>
using namespace std;
int a,b;
string aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa;
	cin>>b>>bb;
	if(a==b){
		cout<<1;
		if(aa[0]==bb[0]&&aa[1]==bb[1]){
			cout<<1;
			if((aa[2]=='A'||aa[2]=='B'||aa[2]=='C')&&(bb[2]=='A'||bb[2]=='B'||bb[2]=='C')||(aa[2]=='D'||aa[2]=='F')&&(bb[2]=='D'||bb[2]=='F')){
				cout<<1;
				if((aa[2]=='A'&&bb[2]=='B')||(aa[2]=='B'&&bb[2]=='A')||(aa[2]=='B'&&bb[2]=='C')||(aa[2]=='C'&&bb[2]=='B')||(aa[2]=='F'&&bb[2]=='D')||(aa[2]=='D'&&bb[2]=='F')){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
