#include<bits/stdc++.h>
using namespace std;
int w[32];
struct node{
	int nxt,t,pr;
}a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	a[0].nxt = 1;
	int n,m,n2;
	cin>>n>>m;
	n2 = n;
	int x;
	for(int i = 1;i<=n;i++){
		cin>>x;
		a[i].t = x;
		a[i].pr = i-1;
		a[i].nxt = i+1;
		for(int i = 0;i<=30;i++)if((x&(1<<i)))w[i]++;
	}
	a[n+1].pr = n;
	bool ok = 0;
	for(int i = 30;i>=0;i--){
		if(m>w[i])continue;
		ok = 1;
		int o = a[0].nxt;
		while(o<=n2){
			int s = a[o].t;
			if(!(s&(1<<i))){
				n--;
				a[a[o].pr].nxt = a[o].nxt;
				a[a[o].nxt].pr = a[o].pr;
				o = a[o].pr;
				for(int j = 0;j<=30;j++)if((s&(1<<j)))w[j]--;
			}
			o = a[o].nxt;
		}
	}
	if(!ok)cout<<0;
	else{
		int ans2 = (1<<30)-1;
		int o = a[0].nxt;
		while(o<=n2){
			ans2 = (ans2&a[o].t);
			o = a[o].nxt;
		}
		cout<<ans2<<'\n';
	}
	return 0;
}
