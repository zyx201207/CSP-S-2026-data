#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,d,a[N],cnt,flag;
void dfs(int l,int r,int step){
	if(step<0||(step==0&&l!=r))return;
	if(l==r&&step==0){
		cnt++;
		return;
	}
	for(int i=r;i>=l+1;i--){
		if(a[i]-a[l]>d)continue;
		int used=cnt;
		dfs(i,r,step-1);
		if(used==cnt)break;
		if(cnt>2)break;
	}
}
int check(int l,int r){
	int step=0,lst=l;cnt=0;
	for(int i=l;i<r;i++){
		if(a[i+1]-a[lst]>d){
			lst=i;
			step++;
		}
	}
	if(r!=lst)step++;
	dfs(l,r,step);
	if(cnt==2)return 1;
	else return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n<=3){
			cout<<0<<'\n';
			continue;
		}
		if(c==11||c==12){
			int x=d/(a[2]-a[1]);
			if(x<=1||n-2*x+1<=0){
				cout<<0<<'\n';
				continue;
			}
			cout<<n-2*x+1<<'\n';
		}
		else if(c==13||c==14){
			int ans=0;
			for(int i=1;i<=n;i++){
				int ctr=upper_bound(a+1,a+n+1,a[i]+d)-1-a;
				if(ctr<=2){
					continue;
				}
				int fst=upper_bound(a+1,a+n+1,a[ctr-2]+d)-1-a;
				int lst=upper_bound(a+1,a+n+1,a[ctr-1]+d)-1-a;
				ans+=lst-fst;
			}
			cout<<ans<<'\n';
		}
		else{
			int ans=0;
			for(int l=1;l<=n-3;l++){
				for(int r=l+3;r<=n;r++){
					ans+=check(l,r);
				}
			}
			cout<<ans<<'\n';
		}
	}
}
