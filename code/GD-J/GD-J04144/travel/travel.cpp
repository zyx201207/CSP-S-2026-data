#include<bits/stdc++.h>
using namespace std;
char c2[3],s2[3];
string c1,s1;
bool Sl,Sx;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>c2[1]>>c2[2]>>c2[3]>>s1>>s2[1]>>s2[2]>>s2[3];
    int numc=(c2[1]-'0')*10+(c2[2]-'0');
    int nums=(s2[1]-'0')*10+(s2[2]-'0');
    if(c1==s1){
    	cout<<1;
    	Sx=true;
	}
	else cout<<0;
	if(Sx&&numc==nums){
		cout<<1;
		Sl=true;
	}
	else cout<<0;
	if(Sx&&((c2[3]<='C'&&c2[3]>='A'&&s2[3]<='C'&&s2[3]>='A')||((c2[3]=='D'||c2[3]=='F')&&(s2[3]=='D'||s2[3]=='F')))){
		cout<<1;
	}
	else cout<<0;
	if(c2[3]==s2[3]&&abs(numc-nums)==1||((Sl&&(abs(c2[3]-s2[3])==1)&&!(c2[3]=='D'&&s2[3]=='C')&&!(s2[3]=='D'&&c2[3]=='C')||(c2[3]=='D'&&s2[3]=='F')||(s2[3]=='D'&&c2[3]=='F'))))cout<<1;
	else cout<<0;
	return 0;
}
