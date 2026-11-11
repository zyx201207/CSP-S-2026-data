#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b,c,d,e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	cin>>c;
	cin>>b;
	cin>>d;
	if(a!=b)cout<<"0000";
	else{
		cout<<1;
		for(int i=0;i<c.size()-1;i++)e+=c[i];
		for(int i=0;i<d.size()-1;i++)f+=d[i];
		if(e!=f)cout<<"000";
		else{
			cout<<1;
			if((c[c.size()-1]=='A'&&d[d.size()-1]=='B')||(c[c.size()-1]=='B'&&d[d.size()-1]=='A')||(c[c.size()-1]=='B'&&d[d.size()-1]=='C')||(c[c.size()-1]=='C'&&d[d.size()-1]=='B'))cout<<"11";
			else if((c[c.size()-1]=='A'||c[c.size()-1]=='B'||c[c.size()-1]=='C')&&(d[d.size()-1]=='A'||d[d.size()-1]=='B'||d[d.size()-1]=='C'))cout<<"10";
			else if(c[c.size()-1]=='E'&&d[d.size()-1]=='F'||c[c.size()-1]=='F'&&d[d.size()-1]=='E')cout<<"11";
			else cout<<"00";
		}
	}
	return 0;
} //天灵灵，地灵灵，给个一等行不行！ 
