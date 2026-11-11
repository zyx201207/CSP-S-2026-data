#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1;
struct num{
	int l;
	int r;
}a[200005];
bool cmp(num x,num y){
	return x.r>y.r;
}
int sum(int x){
	int cnt=0;
	while(x!=0){
		x/=2;
		cnt++;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==n-1){
		int minn=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			cin>>a[i].l;
			a[i].r=sum(a[i].l);
			minn=min(minn,a[i].r);
		}
		for(int i=1,f=1;i<=n;i++){
			if(a[i].r==minn&&f==1){
				f=0;
				continue;
			}
			ans=(ans&a[i].l);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].l;
		a[i].r=sum(a[i].l);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		ans=(ans&a[i].l);
	}
	cout<<ans;
	return 0;
}
