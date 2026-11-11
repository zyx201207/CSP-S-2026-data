#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ans[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)ans[1]=1;
	else{
		for(int i=1;i<=4;i++)cout<<"0";
		return 0;
	}
	string p1=s1.substr(0,2),p2=s2.substr(0,2);
	//cout<<p1<<" "<<p2;
	if(p1==p2)ans[2]=1;
	else{
		for(int i=1;i<=4;i++)cout<<ans[i];
		return 0;
	}
	string Z1=s1.substr(2,1),Z2=s2.substr(2,1);
	char z1=Z1[0],z2=Z2[0];
	//cout<<z1<<" "<<z2;
	if((z1<='C'&&z2<='C')||(z1>='D'&&z2>='D'))ans[3]=1;
	else{
		for(int i=1;i<=4;i++)cout<<ans[i];
		return 0;
	}
	if(abs(z1-z2)==1)ans[4]=1;
	for(int i=1;i<=4;i++)cout<<ans[i];
	return 0;
} 
//luogu 991587
//genshin impact
