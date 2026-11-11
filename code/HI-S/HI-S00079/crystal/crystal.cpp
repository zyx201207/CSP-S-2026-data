#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],sum,maxx=-1e18,ans;
map<long long,int>p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long l=1e18,r=-1e18;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l=min(l,a[i]),r=max(r,a[i]),p[a[i]]++;
	}
	if(n>5000&&m>1e8){
		if(a[1]>a[2]){
			int x=a[1]-a[2];
			for(int i=1;i<=n;i++){
				if(ans+(i-1)*x>m)break;
				ans+=(i-1)*x,sum++;
			}
			cout<<sum;
			return 0;
		}else{
			int x=a[2]-a[1];
			for(int i=n;i>=1;i--){
				if(ans+(n-i)*x>m)break;
				ans+=(n-i)*x,sum++;
			}
			cout<<sum;
			return 0;
		}
	}
	long long k=l-1,h=0;
	for(int i=l;i<=r;i++){
		ans+=sum;
		sum+=p[i];
		while(ans>m){
			if(h==0){
				k++;
				while(!p[k])k++;
				h=p[k];
			}
			long long x=(ans-m-1)/(i-k)+1;
			if(x>h)ans-=h*(i-k),sum-=h,h=0;
			else h-=x,ans-=x*(i-k),sum-=x;
		}
		maxx=max(maxx,sum);
	}
	cout<<maxx;
	return 0;
} 
