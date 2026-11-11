#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
string c1,s1,c2,s2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	int num1=s1[0]*10+s1[1];
	int num2=s2[0]*10+s2[1];
	if(c1==c2&&num1==num2) cout<<1;
	else cout<<0;
	if(c1==c2&&num1==num2){
		if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]<='D')) cout<<1;
		else cout<<0;
	}else cout<<0;
	if(c1==c2&&num1==num2){
		if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
			if(abs(s1[2]-s2[2])==1){
				cout<<1;
			}else cout<<0;
		}else cout<<0;
	}else cout<<0;
	return 0;
}
