#include<bits/stdc++.h>
using namespace std;
long long a[500123],qz[500123];
int main()
{
	//*
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//*/
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int q=1;q<=n;q++) cin>>a[q];
	sort(a+1,a+1+n);
	for(int q=1;q<=n;q++) qz[q]=qz[q-1]+a[q];
	int ans=0;
	for(int q=1;q<=n;q++)
	{
		int l=1,r=q;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(a[q]*(q-mid)+qz[mid-1]<=m+qz[q-1]) r=mid;
			else l=mid+1;
		}
		ans=max(ans,q-l+1);
	}
	cout<<ans;
	return 0;
}
/*
for q(O(n))
er feng qian w ge(O(log n))
max
O(nlogn)

now-> 14:42
*/


/*
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
//freopen("crystal.in","r",stdin);
//freopen("crystal.out","w",stdout);
//freopen("crystal.in","r",stdin);
//freopen("crystal.out","w",stdout);
me want up mi huo xing wei da shang
so i love CCF
wow i love CCF
i wu yi am happy
but my fenshu is not gao
me wu yi shi fen nu de
beacouse i'm not hui xie

and me am the CQ-J00278
*/
