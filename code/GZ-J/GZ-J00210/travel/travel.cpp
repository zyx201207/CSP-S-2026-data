//GZ-J00210 ∫Î“„÷–—ß —Ó∫∆”Ó 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else {
		cout<<"0000"<<"\n";
		return 0; 
	}
		
	for(int i=0;i<s1.size();i++){
		if(s1[1]==s2[1]) {
			cout<<1;
			if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
				cout<<1;
				break;
		    }
		    else{
		    	cout<<0;
		    	break;
			}
	}
	else {
		cout<<"000"<<"\n";
		return 0;
	}
}
	for(int i=0;i<s1.size();i++){
		if((((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))&&(s1[2]-s2[2]==1||s2[2]-s1[2]==1)){
			cout<<1<<"\n";
			return 0;
		}
		else {
			cout<<0<<"\n";
			return 0;
		}
	}
	return 0;
} 
