#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re return
using p=pair<int,int>;
void solve(){
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1!=s1){
		cout<<"0000";
		return;
	}
	else{
		cout<<"1";
		if(c2.substr(0,2)==s2.substr(0,2)){
			cout<<"1";
			if(((c2[2]=='A' || c2[2]=='C' || c2[2]=='B') && (s2[2]=='A' || s2[2]=='C' || s2[2]=='B')) || ((c2[2]=='D' || c2[2]=='F') && (s2[2]=='D' || s2[2]=='F'))){
				cout<<"1";
				if(c2[2]=='F'){
					c2[2]='E';
				}
				if(s2[2]=='F'){
					s2[2]='E';
				}
				if(abs(s2[2]-c2[2])==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000"; 
		}
		
	}
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--)
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
