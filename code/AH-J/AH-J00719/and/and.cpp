#include <bits/stdc++.h>
using namespace std;
const int max_=2e5+5;
int n,m,a[max_],cnt[30];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		int ans=0;
		for(int i=0;i<(1<<n);i++){
			int tans=-1,qwq=0;
			for(int j=1;j<=n;j++){
				if(i>>j&1){
					qwq++;
					if(tans==-1){
						tans=a[j];
					}else{
						tans&=a[j];
					}
				}
			}
			if(qwq==m){
				ans=max(ans,tans);
			}
		}
		cout<<ans<<'\n';
		exit(0);
	}else if(n<=2000&&(m==1||m==n||m==2)){
		if(m==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				ans=max(ans,a[i]);
			}
			cout<<ans<<'\n';
		}else if(m==n){
			int ans=a[1];
			for(int i=2;i<=n;i++){
				ans&=a[i];
			}
			cout<<ans<<'\n';
		}else if(m==2){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans<<'\n';
		}
		exit(0);
	}else if(m==n-1){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			for(int j=0;j<=21;j++){
				if(a[i]>>j&1){
					cnt[j]++;
				}
			}
			if(i!=1){
				ans&=a[i];
			}
		}
		int qwq=0;
		for(int i=1;i<=n;i++){
			int tans=ans;
			for(int j=0;j<=21;j++){
				if(a[i]>>j&1){
					
				}else if(cnt[j]==n-1){
					tans+=(1<<j);
				}
			}
			qwq=max(qwq,tans);
		}
		cout<<qwq<<'\n';
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,a[i]);
	}
	if(maxx<4){
		int c1=0,c2=0,c3=0;
		for(int i=1;i<=n;i++){
			c1+=(a[i]==1);
			c2+=(a[i]==2);
			c3+=(a[i]==3);
		}
		if(c3>=m){
			cout<<3<<'\n';
		}else if(c2>=(m-c3)){
			cout<<2<<'\n';
		}else if(c1>=(m-c3)){
			cout<<1<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}
	return 0;
}
