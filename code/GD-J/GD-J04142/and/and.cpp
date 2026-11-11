#include<bits/stdc++.h>
using namespace std;
int n,m,sum[32],num;
long long a[200005],ans,x[32][200005],b[200005];
int main(){
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;++i)ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;++i)ans=max(a[i],ans);
		cout<<ans;
		return 0;
	}
	if(m==2&&n<=10000){
		for(int i=1;i<=n-1;++i)
			for(int j=i+1;j<=n;++j)ans=max((a[i]&a[j]),ans);
		cout<<ans;
		return 0;
	}
	if(m==3&&n<=400){
		for(int i=1;i<=n-2;++i)
			for(int j=i+1;j<=n-1;++j)
				for(int k=j+1;k<=n;++k)ans=max((a[i]&a[j]&a[k]),ans);
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;++i){
		b[i]=a[i];
		num=1;
		while(b[i]){
			x[num][i]=b[i]%2;
			b[i]/=2;
			num++;
		}
	}
	num=0;
	for(int i=31;i>=1;--i){
		num=0;
		for(int j=1;j<=n;++j)
			if(x[i][j]==1)num++;
		if(num>=m){
			sum[i]=1;
			for(int j=1;j<=n;++j)
				if(x[i][j]==0)
					for(int k=1;k<=31;++k)x[k][j]=0;
		}
	}
	num=1;
	for(int i=1;i<=31;++i){
		ans+=sum[i]*num;
		num*=2;
	}
	cout<<ans;
	return 0;
}
