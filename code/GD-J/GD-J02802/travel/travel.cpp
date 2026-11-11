#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
bool f1,f2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else ans+='1';
	string rt1="",rt2="";
	char g1,g2;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0' && s1[i]<='9'){
			rt1+=s1[i];
		}
		else g1=s1[i];
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0' && s2[i]<='9'){
			rt2+=s2[i];
		}
		else g2=s2[i];
	}
	if(rt1==rt2) ans+='1';
	else{
		cout<<"1000";
		return 0;
	}
	int k1=0,k2=0;
	if(g1>='A' && g1<='C')  k1=1;
	else k1=2;
	if(g2>='A' && g2<='C') k2=1;
	else k2=2;
	if(k1!=k2){
		cout<<"1100";
		return 0;
	}
	else ans+='1';
	int u=(int)(g1-'A'+1);
	int v=(int)(g2-'A'+1);
	if(abs(u-v)==1) ans+='1';
	else ans+='0';
	cout<<ans;
	return 0;
}
