#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500;
int c,T;
ll pos[N],step[N];//min step 
ll cnt[N][N];//the num of Ith island with j steps;  
ll res;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		int n;
		ll d;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&pos[i]);
			if(i==1) continue;
			ll t=pos[i]-d;
			int l=1,r=i,ans;
			while(l<=r){ //the farthest pos
				int mid=(l+r)>>1;
				if(pos[mid]>=t){
					ans=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			//cout<<"#"<<ans<<endl;
			step[i]=step[ans]+1;
			cnt[i][step[i]]++;
			for(int j=ans;j<i;j++){
				for(int k=step[j];k<=j-1;k++){
					if(j==ans && k==step[j]+1) continue;
					cnt[i][k+1]+=cnt[j][k];
				}
			}
			for(int j=step[ans];j>0 && j<=i-1;j++){
				ll num=0;
				for(int k=ans;k<i;k++){
					//cout<<j<<" "<<k<<" "<<cnt[k][j]<<endl;
					num+=cnt[k][j];
				}
				if(num==2) res++;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
} 
