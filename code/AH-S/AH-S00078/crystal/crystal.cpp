#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],d[500010],maxx=-1,b[500010],tmp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long k=a[2]-a[1],k1=0;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=k){
			k1=1;
			break;
		}
	}
	if(!k1&&n>5000){
		long long sum=1,tt;
		for(int i=1;;i++){
			tt=tt+2*i*k;
			sum+=2;
			if(sum>=n){
				cout<<n<<endl;
				return 0;
			}
			if(m-tt<0){
				if(m+i*k>0)cout<<sum-1;
				else if(m+2*i*k>0)cout<<sum-2;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)d[i]=d[i-1]+a[i];
	long long minn=1e18,id=1,zong=1;
	for(int i=1;i<=n;i++){
		if(minn>d[n]-d[i]+(2*i-1-n)*a[i]-d[i-1]){
			minn=d[n]-d[i]+(2*i-1-n)*a[i]-d[i-1];
			id=i;
			zong=1;
		}
	}
	for(int i=1;i<=n;i++)if(i!=id)b[++tmp]=abs(a[id]-a[i]);
	sort(b+1,b+1+tmp);
	long long xb=1;
	while(m>0){
		if(xb==tmp+1)break;
		m-=b[xb];
		xb++;
		zong++;
		maxx=max(maxx,zong);
	}
	cout<<maxx;
	return 0;
}
