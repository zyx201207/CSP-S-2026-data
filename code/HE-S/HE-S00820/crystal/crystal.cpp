#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[500010];
long long c[500010],p[500010];
long long ans=0;
bool f1=true;
/*
6 14
2 4 6 8 10 12
*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		if(i!=2 && c[i]!=c[i-1]) f1=false;
//		cout<<c[i]<<" ";
	}
	if(f1==true){
		if(c[n]==0){
			cout<<n;
			return 0;
		}
		int can=m/c[n];
//		cout<<can<<endl;
		long long cnt=0;
		int neednum[500010];
		neednum[0]=0;
		for(int i=1;i<=n;i++){
			neednum[i]=(a[n]-a[i])/c[n];
			neednum[i]+=neednum[i-1];
//			cout<<neednum[i]<<" ";
		}
		for(int i=1;i<=n;i++){
//			cout<<neednum[n-1]-neednum[i]<<" "<<can<<endl;
			if(neednum[n-1]-neednum[i]<=can){
				cnt=n-i-1;
				break;
			}
		}
		cnt++;
		cout<<cnt;
		return 0;
	}
	p[0]=0;
	p[1]=0;
//	cout<<endl;
	for(int i=2;i<=n;i++){
		p[i]=p[i-1]+c[i];
//		cout<<p[i]<<" ";
	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
//		cout<<i<<endl;
		long long cost=0,cnt=1;
		for(int j=i-1;j>=1;j--){
			cost+=p[i]-p[j];
//			cout<<i<<" "<<j-1<<" "<<cost<<endl;
			if(cost>m) break;
			cnt++;
		}
		ans=max(cnt,ans);
///		cout<<endl<<ans<<endl;
	}
	cout<<ans;
	return 0;
} 
