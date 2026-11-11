#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000006];
bool b[2000006];
long long n,d,ans=0;
void sol() {
	cin>>n>>d;
	ans=0;
	int op=1,ca=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		b[i]=0;
		if(i>2&&a[i]-a[i-1]!=ca) {
			op=0;
		}
		if(i>2&&a[i]-a[i-1]>d) {
			b[i]=1;
		}
		if(i==2)ca=a[2]-a[1];
	}
	if(n==1||ca==0){
		cout<<"0"<<endl;
		return ;
	}
	if(op==1) {
		if(ca==d||ca>d) {
			cout<<"0"<<endl;
		} else {
			int kk=d/ca;
			cout<<max(n-2*kk+1,0ll)<<endl;
		}
		return;
	}
	op=-1;
	for(int i=1; i<=n; i++) {
		if(!(a[i]-a[1]>d||a[n]-a[i]>d)) {
			op=i;
			break;
		}
	}
	if(op!=-1) {
		cout<<"0"<<endl;
		return;
	}
	int sum=0;
	if(n<=3010) {
		int js=0;
		for(int i=1; i<=n; i++) {
			for(int j=i+2; j<=n; j++) {
				if(a[j]-a[i]<=d)continue;
				js=0;
				for(int k=i+1; k<j; k++) {
					if((a[k]-a[i]<=d&&a[j]-a[k]<=d&&!(a[j]-a[k]==d&&a[k]-a[i]==d))) {
						js++;
					} else {
						int js1=k+1,js2=k-1;
						for(; a[js1]-a[js1-1]==d&&js1<j; js1++);
						for(; a[js2+1]-a[js2]==d&&js>i; js1--);
						if((js1==j||a[j]-a[k]<d)&&(js2==i||a[k]-a[i]<d))js++;
					}
					if(js>2)break;
				}
				if(js==2)ans++;
			}
		}
		cout<<ans<<endl;
		return;
	}
	for(int i=1; i<=n; i++) {
		if(b[i+1]==1)break;
		for(int j=i+2; j<=n; j++) {
			if(b[j]==1)break;
			if(a[j]-a[i]>d&&a[j]-a[i]<2*d) {
				ans++;
				int x=j+1;
				while(x<=n&&a[x]-a[x-1]==d) {
					ans++;
					x++;
				}
			}
		}

	}
	cout<<ans<<endl;
	return;
}
signed main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) {
		sol();
	}
}
