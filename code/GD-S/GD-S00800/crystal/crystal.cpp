#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans;
long long a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long maxx=-100000,minn=100000;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	if(m>=1e18){
		long long cha=a[2]-a[1];
		m/=cha;
		for(int i=1;i<=n;i++){
			if(m>=i){
				m-=i;
				ans++;
			}
			else{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=minn;i<=maxx;i++){
		memset(b,0,sizeof b);
		for(int j=1;j<=n;j++){
			if(a[j]>i) b[j]=-1;
			else{
				b[j]=i-a[j];
			}
		}
		sort(b+1,b+n+1);
		long long cnt=0,tmp=m;
		for(int j=1;j<=n;j++){
			if(b[j]==-1) continue;
			if(tmp>=b[j]){
				tmp-=b[j];
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
