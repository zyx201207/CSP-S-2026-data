#include <bits/stdc++.h>
using namespace std;
long long n,m,k,maxx=1;
int ans[500086];
struct ASD{
	long long val;
	int nums;
}a[500086];
bool cmp(ASD fro, ASD nex){
	return fro.val<nex.val;
}
int P(long long x, int y, int z){
	for (int i=y;i>=1;i--){
		if (x-a[i].nums*(a[y+1].val-a[i].val)>0)
		{
			z+=a[i].nums;
			x-=a[i].nums*(a[y+1].val-a[i].val);
		}
		else{
			return z+=(x/(double)(a[y+1].val-a[i].val));
		}
	}
	return z;
}
int main()
{
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>k;
		bool p=0;
		for (int j=1;j<maxx;j++){
			if (a[j].val==k){
				a[j].nums++;
				p=true;
				break;
			}
		}
		if (p==0) {a[maxx].val=k;a[maxx].nums++;maxx++;}
		}
	sort (a+1,a+maxx,cmp);
	ans[1]=a[1].nums;
	for (int i=1;i<maxx;i++){
		int anss=P(m,i-1,a[i].nums);
		ans[i]=max(ans[i-1],anss);
	}
	cout<<ans[maxx-1];
	return 0;
}
