#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string ch1,ch2;
		ch1+=s1[0];
		ch1+=s1[1];
		ch2+=s2[0];
		ch2+=s2[1];
		if(ch1==ch2){
			cout<<1;
			if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<'D'&&s2[2]<'D')){
				cout<<1;
				if(abs(s1[2]-s2[2])==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
