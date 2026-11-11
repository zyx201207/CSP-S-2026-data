#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a1,b1,a2,b2;
	char c1,c2;
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	cout<<(a1==a2)<<(a1==a2&&b1==b2)<<(a1==a2&&b1==b2&&!((c1<'D')^(c2<'D')))<<(a1==a2&&b1==b2&&!((c1<'D')^(c2<'D'))&&abs(c1-c2)==1);
	return 0;
}
