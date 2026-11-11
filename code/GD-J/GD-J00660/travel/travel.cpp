#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	string a,a1,b,b1;
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<1;
		if(a1[0]==b1[0] && a1[1]==b1[1]){
			cout<<1;
			if((a1[2]=='A' && b1[2]=='B' || b1[2]=='C') || (a1[2]=='B' && b1[2]=='A' || b1[2]=='C') || (a1[2]=='C' && b1[2]=='B' || b1[2]=='A')){
				cout<<1;
				if((a1[2]-'0'+'0'+1)==(b1[2]+'0'-'0')){
					cout<<1;
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
				return 0;
			}			
		}
		else{
			cout<<"000";
			return 0;}
	}
	else{
		cout<<0000;
		return 0;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
