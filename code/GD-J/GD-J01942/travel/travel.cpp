#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	for(long long i=0;i<c1.size();i++)
		if(c1[i]!=c2[i]){
			for(long long j=1;i<=4;i++)
				cout<<0;
			return 0;
		}
	cout<<1;
	for(long long i=0;i<2;i++)
		if(s1[i]!=s2[i]){
			for(long long j=1;i<=3;i++)
				cout<<0;
			return 0;
		}
	cout<<1;
	if(s1[2]<='C'&&s2[2]>='D'||s2[2]<='C'&&s1[2]>='D'){
		cout<<0<<0;
		return 0;
	}
	cout<<1;
	long long a=s1[2]-'A',b=s2[2]-'A';
	if(abs(a-b)==1) cout<<1;
	else cout<<0;
	return 0;
} 
