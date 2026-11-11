#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long x,id;
}a[200010];
long long  cot(long long x){
	long long cnt=0;
	while(x){
		cnt++;
		x&=x-1;
	}
	return cnt;
}
bool cmp(const stu &x,const stu &y){
	if(x.x!=y.x){
		return x.x>y.x;
	}
	return x.id>y.id;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i].id;
	}
	long long ans;
	if(m==n){
		ans=a[1].id;
		for(int i=2;i<=n;i++){
			ans=ans&a[i].id;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i].x=cot(a[i].id);
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].id;
	for(int i=2;i<=m;i++){
		ans=ans&a[i].id;
	}
	cout<<ans;
    return 0;
}
