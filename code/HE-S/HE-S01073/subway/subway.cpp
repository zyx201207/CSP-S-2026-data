#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int m1[m+1];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>m1[i];
	}
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<y*m1[1];
	}
}
