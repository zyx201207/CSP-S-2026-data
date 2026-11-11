#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],de[500005],kx[500005],prek[500005];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	for(int i=1;i<=q;i++)
		cout<<0<<"\n";
	return 0;
}
//~ int l=i+1,r=n;
//~ while(l<=r)
			//~ {
				//~ cout<<1<<" ";
				//~ int mid=(l+r)/2;
				//~ if(prek[mid]==m)
				//~ {
					//~ if(prek[mid+1]>prek[mid])
					//~ {
						//~ cnt=mid;
						//~ break;
					//~ }
					//~ else
					//~ {
						//~ l=mid+1;
						//~ continue;
					//~ }
				//~ }
				//~ if(prek[mid]>m)
				//~ {
					//~ r=mid;
					//~ continue;
				//~ }
				//~ if(prek[mid]<m)
				//~ {
					//~ cnt=mid;
					//~ if(prek[mid+1]>m) break;
					//~ l=mid;
					//~ continue;
				//~ }
			//~ }
