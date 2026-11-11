#include<bits/stdc++.h>
using namespace std;
#define int long long

string c1,s1,c2,s2;
string s;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		s+='1';
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				s="1000";
				cout<<s<<endl;
				return 0;
			}else{
				continue;
			}
		}
		s+='1';
		int t1=s1[2]-'A'+1,t2=s2[2]-'A'+1;
		if((t1<=3 && t2>3) || (t1>3 && t2<=3)){
			s="1100";
			cout<<s<<endl;
			return 0;
		}
		s+='1';
		if(abs(s1[2]-s2[2])>1){
			s="1110";
			cout<<s<<endl;
			return 0;
		}
		s+='1';
	}else{
		s="0000";
		cout<<s<<endl;
		return 0;
	} 
	cout<<s<<endl;
	return 0;
}
