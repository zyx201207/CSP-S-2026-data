//蒋木铮 GZ-J00132 贵阳第一中学 
#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool f1,f2,f3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	//step1
	if(a==c) cout<<1,f1=1;
	else cout<<0;
	//step 2
	if(f1&&b[0]==d[0]&&b[1]==d[1]) cout<<1,f2=1;
	else cout<<0;
	//step 3
	if(f1&&f2&&(b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
		cout<<1,f3=1;
	}
	else if(f1&&f2&&(b[2]=='D'||b[2]=='E')&&(b[2]=='D'||b[2]=='E')){
		cout<<1,f3=1;
	}
	else cout<<0;
	//step4
	if(f3&&b[2]==d[2]+1&&b[2]!='C') cout<<1;
	else if(f3&&b[2]==d[2]-1&&b[2]!='D') cout<<1;
	else cout<<0;
	return 0;
}
