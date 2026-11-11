#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const long long inf=1e13;
string c1,s1,c2,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool ans=1;
	ans=ans&&(c1==c2);
	cout<<int(ans);
	char cc1=s1.back();
	char cc2=s2.back();
	s1.pop_back();
	s2.pop_back();
	ans=ans&&(s1==s2);
	cout<<int(ans);
	if(cc1>cc2) swap(cc1,cc2);
	ans=ans&&((cc1=='D'&&cc2=='F')||(cc1!='D'&&cc2!='F'&&cc2!='D'&&cc1!='F'));
	cout<<int(ans);
	ans=ans&&(abs(cc1-cc2)==1);
	cout<<int(ans);
	return 0;
}

