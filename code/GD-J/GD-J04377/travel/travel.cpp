#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0') x=x*10+(c-'0'),c=getchar();
	return f*x;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		string ss1=s1.substr(0,2),ss2=s2.substr(0,2);
		if(ss1==ss2){
			cout<<'1';
			int ce1=s1[2]-'A',ce2=s2[2]-'A';
			if((ce1<=2&&ce2<=2)||(ce1>2&&ce2>2)){
				cout<<'1';
				if(abs(ce1-ce2)==1) cout<<'1';
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
