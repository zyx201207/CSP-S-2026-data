#include <bits/stdc++.h>
using namespace std;
string c1,c2;
string s1="01A",s2="01B";
void solve(){
	if(c1==c2){
		cout<<1;
		bool f=0;
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				f=1;
			}
		}
		if(f){
			cout<<"000";
			return ;
		}
		cout<<1;
		bool yca_c='A'<=s1[2] && s1[2]<='C'&& 'A'<=s2[2] && s2[2]<='C';
		bool ycd_f='D'<=s1[2] && s1[2]<='F'&& 'D'<=s2[2] && s2[2]<='F';
		if(!(yca_c || ycd_f)){
			cout<<"00";
			return ;
		}
		cout<<1;
		int xl=s1[2]-s2[2];
		if(xl<0)xl*=-1;
		if(xl!=1){
			cout<<0;
			return ;
		}
		cout<<1;	
	}
	else cout<<"0000";
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1;
	cin>>c2>>s2;
	solve();
	
	return 0;
}
