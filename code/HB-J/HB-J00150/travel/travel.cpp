#include <bits/stdc++.h>
using namespace std;
const int N=150;
bool d[N][N],p[N][N];
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	d['A']['B']=d['B']['C']=d['A']['C']=true;
	d['B']['A']=d['C']['B']=d['C']['A']=true;
	d['D']['F']=d['F']['D']=true;
	p['A']['B']=p['B']['C']=true;
	p['B']['A']=p['C']['B']=true;
	p['D']['F']=p['F']['D']=true;
	int x,y;
	string a,b;
	cin>>x>>a>>y>>b;
	if(x!=y) cout<<"0000\n";
	else if(a.substr(0,2)!=b.substr(0,2)) cout<<"1000\n";
	else if(!d[a[2]][b[2]]) cout<<"1100\n";
	else if(!p[a[2]][b[2]]) cout<<"1110\n";
	else cout<<"1111\n";
	return 0;
}
