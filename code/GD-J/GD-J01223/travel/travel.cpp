# include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c)return cout<<"0000",0;//不同车厢 
	if(b[0]!=d[0]||b[1]!=d[1])return cout<<"1000",0;//不同排 
	int L1=b[2]<='C',L2=d[2]<='C';
	if(L1!=L2)return cout<<"1100",0;//在过道两侧 
	
	if(b[2]=='C'&&d[2]=='A')return cout<<"1110",0;//不相邻 
	if(b[2]=='A'&&d[2]=='C')return cout<<"1110",0;//不相邻
	cout<<"1111";//完美座位。 
}
