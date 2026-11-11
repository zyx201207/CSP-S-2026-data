#include<bits/stdc++.h>
using namespace std;
int c1,c2,r1,r2;
char l1,l2;
string s;
int ans[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>c1;
	cin>>s;
	r1=(s[0]-'0')*10+(s[1]-'0');
	l1=s[2];
	cin>>c2;
	cin>>s;
	r2=(s[0]-'0')*10+(s[1]-'0');
	l2=s[2];
	if(c1==c2){
		ans[0]=1;
		if(r1==r2){
			ans[1]=1;
			if((l1<='C' && l2<='C') || (l1>='D' && l2>='D')){
				ans[2]=1;
				if((l1=='A' && l2=='C') || (l1=='C' && l2=='A'))ans[3]=0;
				else ans[3]=1; 
			}
		}
	}
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3]; 
	return 0;
} 
