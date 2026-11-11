#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],sum[500005],dcsl[500005];
struct node{
	int sl,cha;
}b[500005];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		m-=(a[i+1]-a[i])*i;
		if(m<0){
			cout<<i;
			return ;
		}
	}
	cout<<n;
	return ;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}


/*

8 15
1 3 5 7 9 11 13 15


#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
struct node{
	int aa,sl,cha;
}b[500005];
struct node2{
	int sum,sls,cha;
}c[500005];

bool check(int x,int i){
	if(c[i].sum-c[x].sum>m){
		return 1;
	}else{
		return 0;
	}
}
signed main(){
	freopen("crystal3.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ll=1;
	b[1].aa=a[1];
	b[1].sl=1;
	for(int i=2;i<=n;i++){
		if(a[i]==b[ll].aa){
			b[ll].sl++;
		}else{
			b[ll].cha=a[i]-b[ll].aa;
			ll++;
			b[ll].aa=a[i];
			b[ll].sl=1;
		}
	}
	for(int i=1;i<=ll;i++){
	//	cout<<b[i].aa<<" "<<b[i].sl<<" "<<b[i].cha<<'\n';
		c[i].sum+=c[i-1].sum+b[i].sl*b[i].cha;
		c[i].sls=c[i-1].sls+b[i].sl;
		c[i].cha=c[i-1].cha+b[i].cha;
	//	cout<<c[i].sum<<" "<<c[i].sls<<" "<<c[i].cha<<'\n';
	}
	int ans=0;
	for(int i=1;i<=ll;i++){
		int cnt=0;
		if(c[i].sum<=m){
			cnt=c[i].sls+b[i+1].sl;
		}else{
			int l=1,r=i,x=1e18;
			while(l<=r){
				int mid=(l+r)>>1;
				if(check(mid,i)){
					l=mid+1;
					x=mid;
				}else{
					r=mid-1;
					x=mid;
				}
			}
			
			if(c[i].sum-c[x].sum==m){
				cnt=c[i].sls-c[x].sls;
			}else{
				int ss=c[i].sum-c[x].sum;
				ss=m-ss;
			//	cout<<x<<" "<<i;
		//		return 0;
				if(c[i].cha==c[x].cha) continue;
				ss=(ss+1-c[i].cha+c[x].cha)/(c[i].cha-c[x].cha);//
				cnt=c[i].sls-c[x].sls+ss+b[i+1].sl;
			//	cout<<i<<" "<<x<<" "<<cnt<<"---------------\n";
			}
			
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
/*
14 18
2 2 7 7 9 9 9 9 9 9 9 9 10 10
*/















