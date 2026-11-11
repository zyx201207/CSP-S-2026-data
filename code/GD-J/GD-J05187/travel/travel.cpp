#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string st;
st s1,s2,s3,s4;
bool b1,b2,b3,b4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000\n";
		return 0;
	}
	b1=1;
	if(s2[0]==s4[0] and s2[1]==s4[1]){
		b2=1;
		if((s2[2]=='D' and s4[2]=='F')or(s4[2]=='D' and s2[2]=='F')or(s2[2]>='A' and s2[2]<='C' and s4[2]>='A' and s4[2]<='C')){
			b3=1;
			if((s2[2]=='D' and s4[2]=='F')or(s4[2]=='D' and s2[2]=='F')or(abs(s4[2]-s2[2])==1)) b4=1;
		}
	}
	cout<<b1<<b2<<b3<<b4<<'\n';
	return 0;
}
