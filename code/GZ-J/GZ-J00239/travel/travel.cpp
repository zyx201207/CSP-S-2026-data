//GZ-J00239 ñûĞÅÖ² 
#include<bits/stdc++.h>
using namespace std;
int a1,b1;
string a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
		int s1=a2.size();
		int s2=b2.size();
		if(s1==s2){
			for(int i=0;i<s1-1;i++){
				if(a2[i]!=b2[i]){
					cout<<"000";
					return 0;
				}
			}
			cout<<1;
			if((a2[s1-1]<='C'&&b2[s2-1]<='C')||(a2[s1-1]>'C'&&b2[s2-1]>'C')){
				cout<<1;
				if((a2[s1-1]+1==b2[s2-1])||(a2[s1-1]-1==b2[s2-1])){
					cout<<1;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
	}
	else cout<<"0000";
	return 0;
}
