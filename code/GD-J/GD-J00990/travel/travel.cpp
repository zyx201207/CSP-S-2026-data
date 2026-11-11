#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool x[256];
bool close(char a, char b){
	if(a='A')return b=='B';
	if(a='B')return b=='A'||b=='C';
	if(a='C')return b=='B';
	if(a='D')return b=='F';
	if(a='F')return b=='D';
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a,b,c,d,e,f;
	cin>>a>>b>>c>>d;
	x['A']=x['B']=x['C']=1;
	e=b,f=d,e.pop_back(),f.pop_back();
	cout<<((a==c))<<((a==c)&&(e==f))<<((a==c)&&(e==f)&&
	(x[b.back()]==x[d.back()]))<<((a==c)&&(e==f)&&
	(x[b.back()]==x[d.back()])&&close(b.back(),d.back()));
	return 0;
} 
