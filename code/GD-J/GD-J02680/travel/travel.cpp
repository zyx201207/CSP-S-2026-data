#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<0<<0<<0<<0;
	}
	else{
		cout<<1;
		if(s1[0]+s1[1]!=s2[0]+s2[1]){
			cout<<0<<0<<0;
		}else{
			cout<<1;
			int a=s1[2]-'A',b=s2[2]-'A';
			if((a>=3 && b<=2)||(a<=2 && b>=3)){
				cout<<0<<0;
			}else{
				cout<<1;
				if((s1[2]+1==s2[2] || s1[2]-1==s2[2]) || (s1[2]=='D' && s2[2]=='F')){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}
	}
	
	return 0;
}
