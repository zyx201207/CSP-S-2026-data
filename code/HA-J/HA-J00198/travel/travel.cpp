#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
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
	char a1=s1[s1.size()-1],a2=s2[s2.size()-1];
	if(a1=='F') a1='E';
	if(a2=='F') a2='E';
	if(s1[1]!=s2[1]||s1[0]!=s2[0]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(('A'<=a1&&a1<='C'&&(a2=='E'||a2=='D'))||('A'<=a2&&a2<='C'&&(a1=='E'||a1=='D'))){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(int(a1-a2))!=1){
		cout<<"0";
		return 0;
	}
	cout<<1;
	return 0;
}
