#include<bits/stdc++.h>
#define ll long long
using namespace std;
//constexpr int N=1e5+5;
string c1,s1,c2,s2;
int main(){
//	freopen("travel5.in","r",stdin);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				cout<<1;
				char a=s1[2],b=s2[2];
				if(a>b) swap(a,b);
				if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F')) cout<<1;
				else cout<<"0";
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
