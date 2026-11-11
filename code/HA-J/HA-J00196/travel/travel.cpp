#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10;
int n,a[N],p;string s1,s2,r1,r2;char s,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s1>>s2>>r1>>r2;
	if(s1==r1){
		for(int i=0;i<=1;i++)
			if(s2[i]!=r2[i]){
				cout<<"1000";return 0;
			}
		s=s2[2];r=r2[2];
		if((s=='A'&&(r=='B'||r=='C'))||(s=='B'&&(r=='A'||r=='C'))||(s=='C'&&(r=='A'||r=='B'))||(s=='D'&&r=='E')||(s=='E'&&r=='D'))
			if((s=='A'&&r=='B')||(s=='B'&&r=='A')||(s=='B'&&r=='C')||(s=='C'&&r=='B')||(s=='D'&&r=='E')||(s=='E'&&r=='D'))
				cout<<"1111";
			else cout<<"1110";
		else cout<<"1100";
	}
	else cout<<"0000";
	return 0;
}