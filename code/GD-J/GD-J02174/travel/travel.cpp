#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long cnt=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	char c=s1[2],d=s2[2];
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else cnt++;
	long long a=s1[0]-'0'+s1[1]-'0',b=s2[0]-'0'+s2[1]-'0';
	if(a!=b){
		cout<<"1000";
		return 0;
	}
	else cnt++;
	
	if((c>='A'&&c<='C'&&d>='A'&&d<='C')||(c>='D'&&c<='E'&&d>='D'&&d<='E')){
		cnt++;
	}
	else {
		cout<<"1100";
		return 0;
	}
	if(c>='A'&&c<='C'&&d>='A'&&d<='C'){
		if(c=='A'&&d=='B'||c=='B'&&d=='A'||c=='B'&&d=='C'||c=='C'&&d=='B'){
			cnt++;
		}
		else{
			cout<<"1110";
			return 0;
		}
	}
	else if(c>='D'&&c<='E'&&d>='D'&&d<='E'){
		cnt++;
	}
	else cout<<"1110";
	if(cnt==4) cout<<"1111";
	return 0;
}
