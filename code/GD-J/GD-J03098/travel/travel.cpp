#include<bits/stdc++.h>
#define ll long long
using namespace std;
int rc,xc,m[5]={1,1,1,2,2};
char rs[5],xs[5];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc!=xc) cout<<"0000";
	else {
		cout<<"1";
		int r=int(rs[0]-'0')*10+int(rs[1]-'0');
		int x=int(xs[0]-'0')*10+int(xs[1]-'0');
		if(r!=x) cout<<"000";
		else {
			cout<<"1";
			int rz=rs[2]-'A',xz=xs[2]-'A';
			if(m[rz]!=m[xz]) cout<<"00";
			else {
				cout<<"1";
				int t=abs(rz-xz);
				if(t==1) cout<<"1";
				else cout<<"0";
			}
		}
	}
	
	return 0;
}
