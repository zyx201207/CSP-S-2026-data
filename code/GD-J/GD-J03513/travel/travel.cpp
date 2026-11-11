#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		cout<<1;
		int a1=0,a2=0;
		for(int i=0;i<=1;i++){
			a1*=10;a2*=10;
			a1+=s1[i];a2+=s2[i];
		}
		if(a1!=a2){
			cout<<"000";
		}
		else{
			cout<<1;
			if(('A'<=s1[2]&&s1[2]<='C')&&('A'<=s2[2]&&s2[2]<='C')){
				cout<<1;
				int t=s1[2]-s2[2];
				if(abs(t)==1) cout<<1;
				else cout<<0;
			}
			else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
				cout<<"11";
			}
			else cout<<"00"; 
		}
	}
	return 0;
} 
