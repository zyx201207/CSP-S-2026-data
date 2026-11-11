#include <bits/stdc++.h>
using namespace std;
int n,a[200001],x,y,_1,_2,o;
char c[200001];
long long ans;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	x=1,y=n,_1=a[1],_2=a[2];
	while(x<y){
		if(_1==0)_1=a[++x];
		if(_2==0)_2=a[--y];
		if(x>=y)continue;
		o=min(_1,_2);
		if(c[x]!=c[y])ans+=o;
		_1-=o,_2-=o;
	}
	cout<<ans;
	return 0;
}
