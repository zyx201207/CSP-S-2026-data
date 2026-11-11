#include<bits/stdc++.h>
using namespace std;
struct Node{
	int total;
	char ch;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].total>>a[i].ch;
	unsigned long long ans=0;
	int l=1,r=n;
	while(l<r)
	{
		if(a[l].ch!=a[r].ch)
		{
			int aa=min(a[r].total,a[l].total);
			ans+=aa;
			a[r].total-=aa;
			a[l].total-=aa;
		}
		else
		{
			int aa=min(a[r].total,a[l].total);
			a[r].total-=aa;
			a[l].total-=aa;
		}
		if(a[r].total==0) r--;
		if(a[l].total==0) l++;
	}
	cout<<ans;
	return 0;
}
