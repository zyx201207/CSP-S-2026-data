#include<bits/stdc++.h>
using namespace std;

const int MXN = 2e5+3 ;

char c[MXN];
long long res;
int n,a[MXN],pl,pr;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	pl=1;
	pr=n;
	while(pl<pr){
		int mn=min(a[pl],a[pr]);
		a[pl]-=mn;
		a[pr]-=mn;
		if(c[pl]!=c[pr])
			res+=mn;
		if(!a[pl])
			pl++;
		if(!a[pr])
			pr--;
	}
	cout<<res<<"\n";
	return 0;
}