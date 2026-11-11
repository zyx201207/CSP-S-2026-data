#include <bits/stdc++.h>
using namespace std;
vector<int> ans(4);
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	while (a!=10000){
		a++;
	}
	if (a==b) ans[0]=1;
	if (ans[0]==1 && x[0]==y[0] && x[1]==y[1]) ans[1]=1;
	if (ans[1]==1 && ((x[2]-'A'<=2 && y[2]-'A'<=2) || (x[2]-'A'>2 && y[2]-'A'>2))) ans[2]=1;
	if (ans[2]==1 && abs(x[2]-y[2])==1) ans[3]=1;
	for (auto x:ans) cout<<x;
	return 0;
}

