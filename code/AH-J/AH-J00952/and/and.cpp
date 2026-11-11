#include<bits/stdc++.h>
using namespace std;
struct q{
	long long a,b;
}y[200005];
bool cmp(q x,q y){
	if(x.b!=y.b) return x.b>y.b;
	return x.a>y.a;
}
long long n,m,maxx=-1,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>y[i].a;
		long long f=y[i].a;
		while(f){
			if(f%2) y[i].b++;
			f/=2;
		}
		maxx=max(maxx,y[i].a);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	sort(y+1,y+n+1,cmp);
	ans=y[1].a;
	for(int i=2;i<=m;i++){
		ans=ans&y[i].a;
	}
	cout<<ans;
	return 0;
}
