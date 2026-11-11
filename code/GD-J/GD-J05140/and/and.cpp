#include <bits/stdc++.h>
using namespace std;
int n,m;
struct N{
	int a;
	int b;
}x[200005];
int zh(int q){
	int sum=0;
	while (q>0){
		sum+=q%2;
		q/=2;
	}
	return sum;
}
bool cmp(N x,N y){
	return x.b<y.b;
}
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>x[i].a;
		x[i].b=zh(x[i].a);
	} 
	sort(x+1,x+n+1,cmp);
	int ans=x[n].a;
	for (int i=n-1;i>=n-m+1;i--){
		ans&=x[i].a;
	}
	cout<<ans;
}
