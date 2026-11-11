//GZ-J00288 ∑ΩÍ…”Ó 
#include <bits/stdc++.h>
#define upp(i,a,b,c) for(int i=a;i<=b;i+=c)
#define dow(i,a,b,c) for(int i=a;i>=b;i-=c)
#define ll long long
using namespace std;
string co,ct,so,st;
bool checko(char a,char b){
	return ((a=='A' && b=='B')||(a=='B' && b=='A')||(a=='A' && b=='C')||(a=='C' && b=='A')||(a=='B' && b=='C')||(a=='C' && b=='B')||(a=='D' && b=='F')||(a=='F' && b=='D'));
}
bool checkt(char a,char b){
	return ((a=='A' && b=='B')||(a=='B' && b=='A')||(a=='B' && b=='C')||(a=='C' && b=='B')||(a=='D' && b=='F')||(a=='F' && b=='D'));
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>co>>so>>ct>>st;
	if(co==ct) cout<<1;
	else cout<<0;
	if(so[0]==st[0] && so[1]==st[1] && co==ct) cout<<1;
	else cout<<0;
	if(checko(so[2],st[2]) && so[0]==st[0] && so[1]==st[1] && co==ct) cout<<1;
	else cout<<0;
	if(checkt(so[2],st[2]) && checko(so[2],st[2]) && so[0]==st[0] && so[1]==st[1] && co==ct) cout<<1;
	else cout<<0;
	return 0;
}
