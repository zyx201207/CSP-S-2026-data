#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[10000005],ans,m_use,cnt[10000005],all_same=1,sum,sum1,cnt1=1,x,x_same=1,sums[100005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	x=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(a[i]!=i)all_same=0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]+x!=a[i+1]&&i!=n)x_same=0;
	}
	sort(a+1,a+1+n);
	if(all_same){
		while(sum<m&&sum+sum1+1<=m){
			sum1=sum1+1;
			sum=sum+sum1;
			cnt1++;
		}
		cout<<cnt1<<'\n';
	}
	else if(x_same){
		for(int i=1;i<=n;i++){
			sums[i]=sums[i]+i;
			int jsx=x*sums[i];
			if(jsx<=m&&jsx+sums[i]+1<=m)cnt1++;
			else break;
		}
		cout<<cnt1<<'\n';
	}
	else{
		for(int i=2;i<=n;i++){
			cnt[i]=1;
			for(int j=i-1;j>=1;j--){
				m_use=m;
				if((double)clock()/CLOCKS_PER_SEC>0.85)break;
				if(m_use>0&&m_use-(a[i]-a[j])>=0){
					m_use-=(a[i]-a[j]);
					cnt[i]++;
				}
				
			}
			
		}
		for(int i=2;i<=n;i++){
			ans=max(ans,cnt[i]);
		}
		cout<<ans<<'\n';
	}
	
	
	}
	

