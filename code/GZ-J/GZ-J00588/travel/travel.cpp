#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int l1,l2,l3,l4;
bool f1=1,f2=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<3;i++){
		if(c1[i]!=c2[i]){
			f1=0;
			break;
		}
	}
	if(!f1){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			f2=0;
			break;
		}
	}
	if(!f2){
		cout<<"000";
		return 0;
	}
	else{
		cout<<1;
		if(s1[2]<='C'&&s2[2]<='C'){
			cout<<1;
			if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else if(s2[2]>='D'&&s1[2]>='D'){
			cout<<1;
			if(s2[2]==s1[2]||s2[2]+1==s1[2]){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	return 0;
}
