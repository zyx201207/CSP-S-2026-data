#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std; 
struct wxjun
{
	ll id;
	string seat,row,pos;
}a,b;
bool check(string x)
{
	return x=="A"||x=="B"||x=="C";
}
void solve()
{
	cin>>a.id>>a.seat>>b.id>>b.seat;
	a.row=a.seat[0]+a.seat[1],b.row=b.seat[0]+b.seat[1];
	a.pos=a.seat[2],b.pos=b.seat[2];
	cout<<(a.id==b.id)<<((a.id==b.id)&&(a.row==b.row))<<((a.id==b.id)&&(a.row==b.row)&&(check(a.pos)==check(b.pos)));
	cout<<(
	(a.id==b.id)
	&&(a.row==b.row)
	&&(check(a.pos)==check(b.pos))
	&&((a.pos=="A"&&b.pos=="B")||(a.pos=="B"&&b.pos=="C")||(a.pos=="D"&&b.pos=="F")));
	return;
}
int main()
{
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie();
	ll T=1;//cin>>T;
	while(T--)solve();
	return 0; 
}
