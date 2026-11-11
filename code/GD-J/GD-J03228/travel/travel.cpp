#include<bits/stdc++.h>
using namespace std;
long long ans;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	if(c1==c2){
		for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]) break;
		ans++;
	}
	if(ans==2) cout<<1;
	else cout<<0;
	if(ans==2){
		if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D') cout<<1;
	    else cout<<0;
	    if(s1[2]<='C'&&s2[2]<='C'&&s1[2]+1==s2[2]||s1[2]<='C'&&s2[2]<='C'&&s1[2]-1==s2[2]) cout<<1;
	    else if(s1[2]>='D'&&s2[2]>='D'&&s1[2]+1==s2[2]||s1[2]>='D'&&s2[2]>='D'&&s1[2]-1==s2[2]) cout<<1;
	    else cout<<0;
	}
	else cout<<"00";
	}
	else cout<<"000";
	return 0;
}
