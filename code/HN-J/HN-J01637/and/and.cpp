#include<bits/stdc++.h>
using namespace std;
struct N{
	int a,b;
}a[200010];
int n,m;
int qwe(int a){
	int ans=0;
	while(a>0){
		if(a&1) ans++;
		a=(a>>1);
	}return ans;
}bool cmp(N a,N b){
	if(a.b==b.b) return a.a>b.a;
	return a.b>b.b;
}bool cmp2(N a,N b){
	if(a.b==b.b) return a.a>b.a;
	return a.b<b.b;
}bool cmp3(N a,N b){
	return a.a>b.a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;bool o=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
		if(a[i].a!=a[i-1].a)o=0;
		a[i].b=qwe(a[i].a);
	}
	sort(a+1,a+n+1,cmp3);
	int ans=a[1].a;
	for(int i=2;i<=m;i++){
		ans=(ans&a[i].a);
	}
	sort(a+1,a+n+1,cmp2);
	int num=a[1].a;
	for(int i=2;i<=m;i++){
		num=(num&a[i].a);
		if(num<ans) break;
	}
	sort(a+1,a+n+1,cmp);
	int sum=a[1].a;
	for(int i=2;i<=m;i++){
		sum=(sum&a[i].a);
		if(sum<ans||sum<num) break;
	}
	cout<<max(ans,max(num,sum));
	return 0;
}
