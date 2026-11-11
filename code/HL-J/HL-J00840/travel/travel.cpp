#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,c2,s1,s2,ans; 
ll a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	a=int(s1[0]-'0')*10+int(s1[1]-'0');
	b=int(s2[0]-'0')*10+int(s2[1]-'0');
	if(c1==c2){
		ans+='1';
		if(a==b){
			ans+='1';
			if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
				ans+="11";
			}
			else if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
				ans+='1';
				if((int(s1[2]-s2[2])==-1)||(int(s1[2]-s2[2])==1)) ans+='1';
				else ans+='0';
			}
			else ans+="00";
		}
		else ans+="000";
	}
	else ans+="0000";
	cout<<ans;
	return 0;
}