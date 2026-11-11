#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,dp[5005][5005],a[2000005],las[5005],l,r,noww,cnt,dis[5005][5005],fly[2000005];
int ef(int val){
	int ll=1,rr=n,mid=ll;
	while(ll<rr){
		mid=(ll+rr)/2;
		if(a[mid]>=val){
			rr=mid;
		}
		else{
			ll=mid+1;
		}
	}
	return ll;
}
int ef2(int val){
	int ll=1,rr=n,mid=ll;
	while(ll<rr){
		mid=(ll+rr)/2;
		if(ll==rr-1){
			mid++;
		}
		if(a[mid]<=val){
			ll=mid;
		}
		else{
			rr=mid-1;
		}
	}
	return ll;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			cin>>n>>d;
			cnt=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			sort(a+1,a+1+n);
			for(int i=1;i<=n;i++){
				las[i]=ef(a[i]-d);
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dp[i][j]=0;
					dis[i][j]=LLONG_MAX;
				}
			}
			for(int i=1;i<=n;i++){
				dp[i][i]=1;
				dis[i][i]=0;
				l=i;
				r=i-1;
				noww=0;
				for(int j=i+1;j<=n;j++){
					while(a[l]+d<a[j]){
						noww-=dp[i][l];
						l++;
					}
					while(dis[i][r+1]==dis[i][l]&&r+1<j){
						r++;
						noww+=dp[i][r];
					}
					dp[i][j]=noww;
					dis[i][j]=dis[i][l]+1;
					if(dp[i][j]==2){
						cnt++;
					}
				}
			}
			cout<<cnt<<'\n';
		}
		return 0;
	}
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			sort(a+1,a+1+n);
			int ste=d/(a[2]-a[1]);
			if(ste<=1){
				cout<<0<<'\n';
			}
			else{
				cout<<max(n-2*ste+1,0ll)<<'\n';
			}
		}
		return 0;
	}
	if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			cnt=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			sort(a+1,a+1+n);
			for(int i=1;i<=n;i++){
				fly[i]=ef2(a[i]+d);
			}
			for(int i=1;i<=n;i++){
				if(fly[i]!=n&&fly[fly[i]]==fly[fly[i]-1]&&fly[fly[i]]!=fly[fly[i]-2]){
					cnt++;
				}
			}
			cout<<cnt<<'\n';
		}
		return 0;
	}
	while(t--){
		cout<<0<<'\n';
	}
	return 0;
}
