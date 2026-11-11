#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
bool v1,v2,v3,v4;


void solve(){
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		v1=1;
		if(s2[0]==s4[0] && s2[1]==s2[1]){
			v2=1;
			char c1=s2[2],c2=s4[2];
			if((c1<='C' && c2<='C') || (c1>='D' && c2>='D')){
				v3=1;
				if(abs(c1-c2)<=1) v4=1;
				else v4=0;
			} 
			else v3=0,v4=0;
		}
		else v2=v3=v4=0;
	}
	else v1=v2=v3=v4=0;
	cout<<v1<<v2<<v3<<v4<<endl;
	
	
	
	return ;
}






int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	
	
	
	return 0;
} 
