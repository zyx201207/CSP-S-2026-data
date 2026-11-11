#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
	  if(s2[0]==s4[0]&&s2[1]==s4[1]){
	  	if((s2[2]-'A'<3&&s4[2]-'A'<3)||(s2[2]-'A'>=3&&s4[2]-'A'>=3)){
	  	  int c1=s2[2]-'A',c2=s4[2]-'A';
	  	  if(c1>c2) swap(c1,c2);
	  	  if((c1==0&&c2==1)||(c1==1&&c2==2)||(c1==3&&c2==5)) cout<<"1111";
	  	  else cout<<"1110";
		}
		else cout<<"1100";
	  }
	  else cout<<"1000";
	}
	else cout<<"0000";
	return 0; 
}
