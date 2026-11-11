#include<bits/stdc++.h>
#define int long long
using namespace std;
bool f(int x,int y){
	return x>y;
}
int a,b,c[200005],andor=INT_MAX;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++) cin>>c[i];
	sort(c+1,c+a+1,f);
	cout<<c[b];
	return 0;
}
