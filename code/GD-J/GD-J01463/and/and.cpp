#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct qew{
	int a;
	int b;
}a[200005];
ll n,m;
bool cmp(qew x,qew y){
	if(x.b==y.b)return x.a>y.a;
	return x.b>y.b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
		int x=a[i].a;
		while(x){
			if(x&1)a[i].b++;
			x>>=1;
		}
	}
	sort(a+1,a+1+n,cmp);
	ll ans=a[1].a;
	for(int i=2;i<=m;i++)ans&=a[i].a;
	cout<<ans;
		
	return 0;
}
