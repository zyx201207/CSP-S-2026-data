#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
int f2,f3,f1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1,f1=1;
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&f1==1){
		f2=1;
		cout<<1;
	}
	else cout<<0;
	if(f2==1){
		if(s1[2]<='C'&&s2[2]<='C') cout<<1,f3=1;
		else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')) cout<<1,f3=2;
		else cout<<0; 
	} else cout<<0;
	if(f3>0){
		if(f3==2) cout<<1;
		else if(abs((s1[2])-(s2[2]))==1) cout<<1;
		else cout<<0;
	}else cout<<0;
	return 0;
} 
