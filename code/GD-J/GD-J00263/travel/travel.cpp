#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2) {
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			char ch1=s1[2];
			char ch2=s2[2];
			if(ch1-'D'>=0){
				if(ch2-'D'>=0) cout<<11;
				else cout<<"00";
			}
			else{
				if(ch2-'D'>=0) cout<<"00";
				else{
					cout<<1;
					int a=ch1-'A',b=ch2-'A';
					if(a<b) swap(a,b);
					if(a-b<=1) cout<<1;
					else cout<<0;
				}
			}
		}
		else cout<<"000";
			
	}
	else cout<<"0000";
		
	
	
	
	return 0;
}
