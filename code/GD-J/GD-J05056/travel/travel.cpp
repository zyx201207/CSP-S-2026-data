#include<bits/stdc++.h>;
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool ok=1;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
		ok=0;
	}
	if(ok&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<0;
		ok=0;
	}
	if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<'D'&&s2[2]<'D')){
		if(ok){
			cout<<1;
		}
		else cout<<0;
	}
	else{
		cout<<0;
		ok=0;
	}
	if(ok&&((s1[2]>='D'&&s2[2]>='D')||((s1[2]<'D'&&s2[2]<'D')&&(s1[2]-s2[2]==-1||s1[2]-s2[2]==1)))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
