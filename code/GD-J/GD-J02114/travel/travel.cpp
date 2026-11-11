//1~25
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
string c1,c2,s1,s2;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		if((s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') || (s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F')){
			if(abs(s1[2]-s2[2])==1){
				cout<<"1111";
			}else{
				cout<<"1110";
			}
		}else{
			cout<<"1100";
		}
	}else{
		cout<<"1000";
	}
	
	
	
	return 0;
}
