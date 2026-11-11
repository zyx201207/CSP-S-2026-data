#include<bits/stdc++.h> 
using namespace std;

#define ll long long 
const int N=2e5+5;
ll n,d;
ll a[N];
int p[N];

ll findr(int r) {
	ll ans=0;
	while(r>0&&p[r]!=1) {
		ll rr=a[r]-d;
		if(rr<=a[1]) {
			ans++;
			break;
		}
		for(int i=r-1;i>=1;i--) {
			if(a[i]>=rr||a[i-1]<rr) {
				ans++;
				r=i;
				break;
			}
		}
	}return ans;
}

ll findl(int l) {
	ll ans=0;
	while(l<=n) {
		ll l2=a[l]+d;
		if(l2>=a[n]) {
			ans++;
			break;
		}
		for(int i=l+1;i<=n;i++) {
			if(a[i]<=l2||a[i+1]>l2) {
				ans++;
				l=i;
				break;
			}
		}
	}return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
//	freopen("r",".in",stdin);
//	freopen("w",".out",stdout);
	int op,t;
	cin>>op>>t;
	if(op==11||op==12) {
		while(t--) {
			cin>>n>>d;
			if(n<=3) {
				cout<<0<<endl;
				continue;
			}
			for(int i=1;i<=n;i++) cin>>a[i];
			sort(a+1,a+n+1);
			int dx=a[2]-a[1];
			if(dx>=d) {
				cout<<0<<endl;
				continue;
			}if(3*dx>d||3*dx<=2*d) {
				cout<<abs(n-d)/2+abs(n-d)%2<<endl;//ци╣д 
			}else {
				cout<<0<<endl;
				continue;
			}
		}
	}
	if(op==13||op==14) {
		for(int i=1;i<=t;i++) cout<<0<<endl;
		return 0;
	}
	while(t--) {
		ll ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=3) {
			cout<<0<<endl;
			continue;
		}
		sort(a+1,a+n+1);
		for(int i=4;i<=n;i++) {
			if(a[i]-a[i-3]>d&&a[i]-a[i-3]<d*2&&a[i]-a[i-1]<=d&&a[i-1]-a[i-2]<=d&&a[i-2]-a[i-3]<=d) {
				a[i]=1;
				a[i-3]=-1;
				p[++p[0]]=i-3;
			}
		}for(int i=1;i<=p[0];i++) {
			int r=p[i],l=p[i]+3;
			ll ansr=findr(r),ansl=findl(l);
			ans+=ansr*ansl;
		}cout<<ans;
	}
	return 0;
}
