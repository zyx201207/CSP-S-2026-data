#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	long long zhi,yigeshu;
}a[200005];
long long ans;
bool cmp(node x,node y){
	if(x.yigeshu==y.yigeshu){
		return x.zhi>=y.zhi;
	}
	else{
		return x.yigeshu>y.yigeshu;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].zhi;
		long long c=a[i].zhi;
		while(c)
		{
			if((c>>1)==1)
			{
				a[i].yigeshu++;
			}
			c/=2;
		}
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1].zhi;
	for(int i=2;i<=m;i++)
	{
		ans&=a[i].zhi;
	}
	cout<<ans;
	return 0;
}
