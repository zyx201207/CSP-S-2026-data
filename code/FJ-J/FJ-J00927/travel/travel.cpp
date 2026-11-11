#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n1,n2,c1,c2;
string s1,s2,t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>s1>>n2>>s2;
	if(n1==n2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(s1[2]<='C') c1=0;
			else c1=1;
			if(s2[2]<='C') c2=0;
			else c2=1;
			if(c1==c2){
				cout<<1;
				char ch1=s1[2],ch2=s2[2];
				if(abs(ch1-ch2)==1) cout<<1;
				else cout<<0;
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
