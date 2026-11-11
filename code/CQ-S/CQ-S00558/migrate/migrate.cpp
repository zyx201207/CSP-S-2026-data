#include<bits/stdc++.h>
#define int  long long
using namespace std;
const int inf=9e18;
int c,t;
int n,d;
int x[2000005];
int dis[5005][5005],cnt[5005][5005],sum[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		bool flageql=true;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>2)flageql&=((x[i]-x[i-1])==(x[i-1]-x[i-2]));
		}
		if(flageql){
			int tot=0,now=2;
			while(now<=n&&x[now]-x[1]<=d)tot++,now++;
			if(2*tot>n||tot==0)cout<<"0\n";
			else cout<<n-2*tot+1<<"\n";
		}else if(x[n]-x[1]<=2*d){
			int tot=0,mxd=1,frd=1,sed=1;
			for(int i=1;i<=n;i++){
				if(x[i]+d>=x[n])break;
				while(x[i]+d>=x[mxd+1])mxd++;
				if(mxd==i+1)continue;
				while(frd<=n&&x[mxd-2]+d>=x[frd])frd++;
				if(frd==n+1)break;
				while(sed<n&&x[mxd-1]+d>=x[sed+1])sed++;
				if(x[mxd-1]+d>=x[frd]&&frd<=sed)tot+=sed-frd+1;
			}
			cout<<tot<<"\n";
		}else if(n<=5000){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=i;j++)dis[i][j]=inf,cnt[i][j]=sum[i][j]=0;
			}
			dis[1][1]=0,cnt[1][1]=sum[1][1]=1;
			int tot=0;
			for(int i=2,lst=1;i<=n;i++){
				while(x[i]-x[lst]>d)lst++;
				dis[i][i]=0,cnt[i][i]=1;
				for(int j=lst;j<i;j++)dis[i][j]=cnt[i][j]=1;
				for(int j=1;j<lst;j++){
					dis[i][j]=dis[lst][j]+1;
					int l=lst,r=i-1,id;
					while(l<=r){
						int mid=(l+r)/2;
						if(dis[mid][j]==dis[lst][j])id=mid,l=mid+1;
						else r=mid-1;
					}
					cnt[i][j]=sum[id][j]-sum[lst-1][j];
					if(cnt[i][j]==2)tot++;
				}
				for(int j=1;j<=i;j++)sum[i][j]=sum[i-1][j]+cnt[i][j];
			}
			cout<<tot<<"\n";
		}
	}
}
/*
WHAT F**K?!!!
It's to hard! 114514-th harder than crystal and subway!!!
I can't solve it. I can only imagine my WC's experience in future (It's impossible.) in WC of our school.
Or play Genshin Impact.
48-56
*/
