# include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sr1,sr2,sx1,sx2;
	cin>>sr1>>sr2>>sx1>>sx2;
	if(sr1==sx1) cout<<1;
	else cout<<0;
	string x=sr2.substr(0,2),y=sx2.substr(0,2);
	if(sr1==sx1&&x==y) cout<<1;
	else cout<<0;
	char cr=sr2[2],cx=sx2[2];
	if(sr1==sx1&&x==y&&((cr>='D'&&cr<='E'&&cx>='D'&&cx<='E')||(cr>='A'&&cr<='c'&&cx>='A'&&cx<='C'))) cout<<1;
	else cout<<0;
	if(sr1==sx1&&x==y&&((cr=='A'&&cx=='B')||(cr=='B'&&cx=='A')||(cr=='B'&&cx=='C')||(cr=='C'&&cx=='B')||(cr=='D'&&cx=='E')||(cr=='E'&&cx=='D'))) cout<<1;
	else cout<<0;
	return 0;
}
