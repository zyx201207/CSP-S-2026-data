#include<bits/stdc++.h>
using namespace std;
int chex[1001],pai[1001],pan=0;
char s[1001],s1[1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>chex[1]>>pai[1]>>s[1];
	cin>>chex[2]>>pai[2]>>s1[1];
	
	if(chex[1]!=chex[2]){
		cout<<"0000"<<endl;
		return 0;
	}
	else{
		cout<<"1"; 
		if(pai[1]==pai[2]){
			cout<<"1"; 
		}
		if(pai[1]!=pai[2]){
			cout<<"000"; 
			return 0;
		}
//		cout<<s[1]<<s1[1];
		if(s1[1]=='D' && s[1]=='C'){
			cout<<"00";
			return 0;
		}
		else{
			cout<<"1"; 
			int zuo=s[1];
			int you=s1[1];
			if(zuo>you){
				pan=zuo-you;
			}else{
				pan=you-zuo;
			}
			if(pan>=2){
				cout<<"0";
				return 0;
			}else{
				cout<<"1";
				return 0;
			}
		}
	}
}
