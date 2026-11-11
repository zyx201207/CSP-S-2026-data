#include <bits/stdc++.h>
using namespace std;
string s_1,s_2;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s_1>>a>>s_2>>b;
	bool flag=1;
	for(int i=0;i<2;i++){
		if(s_1[i]!=s_2[i]) flag=0;
	}
	if(flag) cout<<1;
	else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	flag=1;
	for(int i=0;i<2;i++){
		if(a[i]!=b[i]){
			flag=0;
		}
	}
	if(flag==1) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	flag=0;
	if(a[2]<='C'&&b[2]<='C') flag=1;
	if(a[2]>='D'&&b[2]>='D') flag=1;
	if(flag==1) cout<<1;
	else cout<<0;
	if(a[2]-b[2]==1||b[2]-a[2]==1){
		if(flag==1) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
