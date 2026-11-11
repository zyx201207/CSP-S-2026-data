#include<iostream>
using namespace std;
int c,t,n;
long long d,x[2000003];
int l[2000003],r[2000003],ans;
int q[2000003],head,tail,dis[2000003],cnt[2000003];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1,ll,rr,mid;i<=n;i++){
			ll=1;rr=i;
			while(ll<rr){
				mid=ll+rr>>1;
				if(x[i]-x[mid]>d)ll=mid+1;
				else rr=mid;
			}
			l[i]=ll;
			ll=i;rr=n;
			while(ll<rr){
				mid=ll+rr+1>>1;
				if(x[mid]-x[i]>d)rr=mid-1;
				else ll=mid; 
			}
			r[i]=ll;
		}
		ans=0;
		for(int i=1,u;i<=n&&x[n]-x[i]>d;i++){
			for(int j=1;j<=n;j++)dis[j]=2654321,cnt[j]=0;
			dis[i]=0;cnt[i]=1;
			q[head=0]=i;tail=1;
			while(head<tail){
				u=q[head];
				head++;
				for(int j=u+1;j<=r[u];j++){
					if(dis[j]>dis[u]+1){
						dis[j]=dis[u]+1;
						cnt[j]=cnt[u];
						q[tail]=j;
						tail++;
					}else if(dis[j]==dis[u]+1){
						cnt[j]+=cnt[u];
						if(cnt[j]>3)cnt[j]=3;
					}
				}
			}
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
