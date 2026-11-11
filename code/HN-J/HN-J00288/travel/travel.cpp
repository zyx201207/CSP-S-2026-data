#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); 
	string s[10];
	int a[10]={};
	cin>>s[1]>>s[2]>>s[3]>>s[4];
	if(s[1]==s[3]){
		a[1]=1;
		if(s[2][0]==s[4][0]&&s[2][1]==s[4][1]){
			a[2]=1;
			if(!(s[2][2]=='D'&&s[4][2]!='F'||s[2][2]=='F'&&s[4][2]!='D'||s[4][2]=='D'&&s[2][2]!='F'||s[4][2]=='F'&&s[2][2]!='D')){
				a[3]=1;
				if(!(s[2][2]=='A'&&s[4][2]=='C'||s[4][2]=='A'&&s[2][2]=='C')){
//					cout<<s[2][2]<<' '<<s[4][2]<<endl;
					a[4]=1;
				} 
			} 
		}
	} 
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
}

