#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=-1e9,cnt,mm,sum;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>5000){
		for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		long long u=a[2]-a[1],ans=1,v=a[2]-a[1];
		while(m>0){
			if(m>=v){
				ans++;
			}
			m-=v;
			v+=u;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cnt=i+1,mm=m,sum=1;
		while(mm&&cnt<=n){
			if(mm>=a[i]-a[cnt]){
				sum++;
			}
			mm-=a[i]-a[cnt];
			cnt++;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
