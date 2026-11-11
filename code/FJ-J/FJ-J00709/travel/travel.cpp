#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c1,c2,a,b,d[10005];
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	d[65]=1;
	d[66]=2;
	d[67]=3;
	d[68]=4;
	d[70]=5;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		a=(s1[0]-'0')*10+(s1[1]-'0');
		b=(s2[0]-'0')*10+(s2[1]-'0');
		if(a==b){
			cout<<1;
			if((s1[2]<='C' && s2[2]<='C') || (s1[2]>='c' && s2[2]>='c')){
				cout<<1;
				if(d[s1[2]]-d[s2[2]]==1 || d[s1[2]]-d[s2[2]]==-1)cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
} 
