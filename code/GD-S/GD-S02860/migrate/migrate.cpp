#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,l[N],r[N];
using ll=long long;
ll d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i],l[i]=r[i]=0;
		for(int i=1,j=1;i<=n;i++){
			while(x[i]-x[j]>d)j++;
			l[i]=j;
		}
		for(int i=n,j=n;i>=1;i--){
			while(x[j]-x[i]>d)j--;
			r[i]=j;
		}
		if(c<=6&&c>=1){
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int te=i;
					int fl=0;
	//				cout<<i<<" "<<j<<" ";
					while(te<=j){
						if(te==r[te]){
							fl=0;
							break;
						}
						int now=r[te];
						if(now>j)now=j;
						if(l[now]==te-1&&te!=i&&(l[te]<=i||l[te-1]==l[te]))fl++;
						te=now;
						if(now==j)break;
					}
	//				cout<<fl<<"\n";
					ans+=(fl==1);
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		if(c==11||c==12){
			ll p=x[2]-x[1],te=d/p;
			if(te<=1)cout<<"0\n";
			else {
				te=te+te-1;
				cout<<max(0ll,n-te)<<"\n";
			}
			continue;
		}
	}
	return 0;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/
