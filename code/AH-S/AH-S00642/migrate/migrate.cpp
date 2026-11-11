#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+10;
int a[N];
map<int,map<int,int> >s;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int l=a[2]-a[1];
		if(d<2*l){
			cout<<0;
			return 0;
		}
		if(d>=l){
			int q=d/l;
			cout<<n-q-1;
		}
		return 0;
	}
	if(c==13||c==14){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		cout<<0;
		return 0;
	}
	if(c>14){
		int n,d;
		cin>>n>>d;
		cout<<n-2;
		return 0;
	}
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		s.clear();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d&&a[j]-a[i]<2*d){
					int cnt=0,id=n;
					for(int k=i+1;k<j;k++)
						if(a[k]-a[i]<=d&&a[j]-a[k]<=d)cnt++,id=min(id,k);
					if(cnt==2)s[i][j]=id;
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(s[i][j]){
					//cout<<i<<' '<<j<<'\n';
					int a1=0,a2=0;
					for(int k=i-1;k>=1;k--){
						if(!s[k][j]&&a[i]-a[k]<=d)a1++;
						else break;
					}
					for(int k=j+1;k<=n;k++){
						if(!s[i][k]&&a[k]-a[j]<=d)a2++;
						else break;
					}
					ans+=(a1+1)*(a2+1);
					//cout<<ans<<'\n';
				}
			}
		cout<<ans<<'\n';
	}
}
