#include<bits/stdc++.h>
using namespace std;
int cx1,cx2,p1,p2,l1,l2;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	cx1=(c1[0]-'0')*10+c1[1]-'0',cx2=(c2[0]-'0')*10+c2[1]-'0';
	if(cx1!=cx2)cout<<"0000",exit(0);
	p1=(s1[0]-'0')*10+s1[1]-'0',p2=(s2[0]-'0')*10+s2[1]-'0';
	if(p1!=p2)cout<<"1000",exit(0);
	l1=s1[2]-'A',l2=s2[2]-'A';
	if((l1<3&&l2<3)||(l1>2&&l2>2)){
		if(l1-l2==1||l2-l1==1)cout<<"1111";
		else cout<<"1110";
	}else cout<<"1100";
	return 0;
}
