#include<bits/stdc++.h>
using namespace std;
char n,m;
int c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>n>>c2>>s2>>m;
	int mod=c1==c2?1:0;
	cout<<mod;
	mod=(s1==s2)&&(c1==c2)?1:0;
	cout<<mod;
	if((n=='A'||n=='B'||n=='C')&&(m=='A'||m=='B'||m=='C')&&mod==1){
		mod=1;
	}
	else if((n=='D'||n=='F')&&(m=='D'||m=='F')&&mod==1){
		mod=1;
	}
	else{
		mod=0;
	}
	cout<<mod;
	int cnt=0;
	if(((n+1==m)||(n-1==m))&&mod==1){
		cnt=1;
	}
	cout<<cnt;
	return 0;
} 
