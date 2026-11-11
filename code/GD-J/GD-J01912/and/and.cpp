#include<bits/stdc++.h>
#define int long long
using namespace std;
struct CC{
	int a,s;
};
CC a[200005];
bool cmp(CC x,CC y){
	if(x.s==y.s) return x.a>y.a;
	return x.s>y.s;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		int x;
		cin>>x;
		a[i].a=x;
		while(x){
			if(x%2==1) a[i].s++;
			x/=2;
		} 
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2; i<=m; i++){
		a[1].a&=a[i].a;
	}
	cout<<a[1].a;
	return 0;
} 
