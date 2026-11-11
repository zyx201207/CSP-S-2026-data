//GZ-J00028 贵阳市白云区华师一学校 白杨梦雪 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	char t1=s1[0],t2=s2[0],t3=s1[1],t4=s2[1];
	if(t1==t2 && t3==t4) cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	char a=s1[2],b=s2[2];
	if((a<='C' && b<='C') || (a>'C' && b>'C')) cout<<'1';
	else{
		cout<<"00";
		return 0;
	}
	if(abs(a-b)==1) cout<<'1';
	else cout<<'0';
	return 0;
}
