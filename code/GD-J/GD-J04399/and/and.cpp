#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct digit{
	long long a,b,c;
};
digit a[200020];
bool cmp(digit x,digit y){
	return x.b>y.b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i].a;
		long long x = a[i].a,ji = 0;
		while(x!=1){
			x/=2;
			ji++;
		}
		a[i].b = ji;
		
	} 
	sort(a+1,a+n+1,cmp);
	long long ans = a[1].a;
	for(int i = 2;i<=m;i++){
		ans=a[i].a&ans;
	}
	cout<<ans;
	return 0;
}
