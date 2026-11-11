#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	int n=s1.size(),m=s2.size();
	s1=" "+s1;
	s2=" "+s2;
	int cnt=0;
	for(int i=1;i<n;i++)cnt=cnt*10+s1[i]-'0';
	int cnt2=0;
	for(int i=1;i<m;i++)cnt2=cnt2*10+s2[i]-'0';
	if(cnt!=cnt2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	char a=s1[n],b=s2[n];
	if(a=='A'&&b=='B'||a=='B'&&b=='A'||a=='B'&&b=='C'||a=='C'&&b=='B'||a=='D'&&b=='F'||a=='F'&&b=='D'){
		cout<<"11";
		return 0;
	}
	if(a=='A'&&b=='C'||a=='C'&&b=='A'){
		cout<<"10";
		return 0;
	}
	cout<<"00";
	return 0;
}
