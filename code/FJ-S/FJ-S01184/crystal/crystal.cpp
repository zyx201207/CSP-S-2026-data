#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 6e5 + 5;

int _, n, m, tot, ans, a[N];

struct mb{
	int x,y;
}p[N];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int kl=a[2]-a[1];
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=kl){
			kl=-91;
			break;
		}
	}
	if(kl!=-91){
		int cnt=0;
		for(int i=1;i<=n-1;i++){
			cnt+=kl*i;
			if(cnt>m){
				cout<<i;
				return;
			}
		}
		cout<<n;
		return;
	}
	int l=1;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			p[++tot].x=a[i-1];
			p[tot].y=l;
			l=1;
		}
		else{
			l++;
		}
	}
	p[++tot].x=a[n];
	p[tot].y=l;
	ans=p[1].y;
	for(int i=2;i<=tot;i++){
		int uu=m,op=p[i].y;
		for(int j=i-1;j>=1;j--){
			if((p[j].y)*(p[i].x-p[j].x)<=uu){
				op+=p[j].y;
				uu-=(p[j].y)*(p[i].x-p[j].x);
			}
			else{
				op+=uu/(p[i].x-p[j].x);
				break;
			}
		}
		ans=max(ans,op);
	}
	cout<<ans;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	_ = 1;
	while(_--){
		solve();
	}
}

