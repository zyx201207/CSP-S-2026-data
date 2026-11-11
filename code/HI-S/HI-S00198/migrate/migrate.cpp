#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int c,t,n,d;
int x[2000005];
int cut[2000005],sum;
int f1[2000005],f2[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		sum=0;
		cut[0]=0;
		for(int i=1;i<n;i++){
			if(x[i+1]-x[i]>d){
				sum++;
				cut[sum]=i;
			}
		}
		for(int i=1;i<=n;i++){
			f1[i]=0;
			f2[i]=0;
		}
		sum++;
		cut[sum]=n;
		int res=0;
		for(int i=1;i<=sum;i++){
			int ans=0;
			int l=cut[i-1]+1,r=cut[i];
			if(r-l+1<=3) break;
			f1[l]=l;
			if(l+1<=r&&x[l+2]-x[l]>d) f1[l+1]=l;
			for(int j=l+1;j<=r;j++){
				if(x[j]-x[j-1]<d&&x[j]-x[j-2]>d) f1[j]=f1[j-1];
				else f1[j]=j;
			}
			for(int j=l;j<=r;j++){
				f2[f1[j]]=j;
			}
			for(int j=l;j<r;j++){
				int las_l=l,las_r=j+1;
				while(las_l<las_r){
					int mid=(las_l+las_r)/2;
					if(x[j+1]-x[mid]<=d) las_r=mid;
					else las_l=mid+1;
				}
				int las=las_l;
				int fore_l=j,fore_r=r;
				while(fore_l<fore_r){
					int mid=(fore_l+fore_r+1)/2;
					if(x[mid]-x[j]<=d) fore_l=mid;
					else fore_r=mid-1;
				}
				int fore=fore_l;
				if(fore-las+1<4) continue;
				ans=ans+(las-f1[las]+1)*(f2[fore]-fore+1);
			}
			res=res+ans;
		}
		cout<<res<<endl;
	}
	return 0;
}
