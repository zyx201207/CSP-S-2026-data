#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],pos,ans=-1;
bool cmp(int x,int y){
	return (x&pos)>(y&pos);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int num=a[i];pos=a[i];
		sort(a+1,a+1+n,cmp);
		for(int i=2;i<=m;i++) num&=a[i];
		ans=max(num,ans);
	}
	cout<<ans;
	return 0;
}
