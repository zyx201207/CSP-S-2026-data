#include<bits/stdc++.h>
using namespace std;
int f(int n){
	int sum=0;
	while(n){
		if(n%2) sum++;
		n/=2;
	}
	return sum;
}
struct st{
	int a;
	int b;
}t[200005];
bool cmp(st x,st y){
	if(x.b==y.b)
		return x.a>y.a;
	return x.b>y.b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t[i].a;
		t[i].b=f(t[i].a);
	}
	sort(t+1,t+n+1,cmp);
	int ans=t[1].a;
	for(int i=2;i<=m;i++){
		ans=ans & t[i].a;
	}
	cout<<ans;
	return 0;
}
