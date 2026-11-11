#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,m,a[N];
int lt,rt,mid,ans;

bool check(int p){
	int sum=0,id=1,mx=1,nw=1;
	for(int i=2;i<=n;i++){
		if(mx>=p) return true;
		int nee=(a[i]-a[i-1])*(i-id);
		sum+=nee;
		//cout<<p<<' '<<i<<' '<<id<<' '<<sum<<'\n';
		if(sum<=m)
			nw=i-id+1;
		else{
			sum-=nee;
			mx=max(mx,nw);
			if(i-id==1){
				id++;
				sum=0;nw=1;
				continue;
			}
			sum-=(a[i-1]-a[id]);
			id++;i--;nw=1;
		}	
	}
	return mx>=p;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	lt=1;rt=n;
	while(lt<=rt){
		mid=(lt+rt)/2;
		if(check(mid)){
			ans=mid;
			lt=mid+1;
		}
		else
			rt=mid-1;
	}
	cout<<ans;
	return 0;
}
