#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char c1,c2;
	int cx = 0,tp = 0,tc = 0,xl = 0;
	cin>>a>>b>>c1>>c>>d>>c2;
	if(a == c)cx = 1;
	else {
		cout<<"0000";
		return 0;
	}
	if(b == d) tp = 1;
	if((c1 <= 'C' && c2 <= 'C') || (c1 > 'C' && c2 > 'C') && b == d) tc = 1;
	if(((b == d + 1 || b == d - 1) && c1 == c2) || ((c1 == c2 - 1 || c1 == c2 + 1) && b == d) && tc == 1)xl = 1;
	cout<<cx<<tp<<tc<<xl;
	return 0;
} 
