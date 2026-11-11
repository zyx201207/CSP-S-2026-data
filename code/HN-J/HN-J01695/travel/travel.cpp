#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2,s3,s4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1;
	cin>>s2;
	cin>>s3;
	cin>>s4;
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
		bool l=true;
		for(int i=0;i<=1;i++){
			if(s2[i]!=s4[i]){
				l=false;
			}
		}
		if(l){
			cout<<1;
			if(s2[2]=='F'&&s4[2]=='D'|| s2[2]!='F'&&s4[2]!='D'){
				cout<<1;
				if(s2[2]=='F'){
					if(s4[2]=='D'){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else if(s2[2]=='C'){
					if(s4[2]=='B'){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else if(s2[2]=='B'){
					if(s4[2]=='C' || s4[2]=='A'){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else if(s2[2]=='A'){
					if(s4[2]=='B'){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<0;
				}
}				
				else{
					cout<<0;
					cout<<0;
				}
}
		else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
}
	return 0;
}
