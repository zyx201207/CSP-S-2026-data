#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans="";
	if(c1==c2){
		ans+="1";
		char o1=s1[0],o2=s2[0],u1=s1[1],u2=s2[1];
		if((o1==o2)&&(u1==u2)){
			ans+="1";
			char a=s1[2],b=s2[2];
			if(a>b)swap(a,b);
			int pd=0;
			int pdd=0;
			if(a=='D'&&b=='F')pd=1,pdd=1;
			if(a=='A'&&b=='B')pd=1,pdd=1;
			if(a=='A'&&b=='C')pd=1;
			if(a=='B'&&b=='C')pd=1,pdd=1;
			if(pd){
				ans+="1";
				if(pdd)ans+="1";
				else ans+="0";
			}else{
				ans+="00";
			}
		}else{
			ans+="000";
		}
	}else{
		ans+="0000";
	}
	cout<<ans<<'\n';
	return 0;
} 
