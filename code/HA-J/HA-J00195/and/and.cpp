#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=1e3+5;
long long n,m,maxn=-1e9;
long long a[N];
long long b[M],c[M],d[M];
long long f(long long x,long long y){
	long long ans=0;
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	int cnt=0;
	while(x>0){
		int num=x%2;
		b[cnt]=num;
		cnt++;
		x/=2;
	}
	int cnt1=0;
	while(y>0){
		int num1=y%2;
		c[cnt1]=num1;
		cnt1++;
		y/=2;
	}
	for(int i=0;i<=max(cnt,cnt1);i++){
		if(b[i]+c[i]==2){
			d[i]=1;
			if(i==0){
				ans+=1;
			}else{
				long long sum=1;
				for(int j=1;j<=i;j++){
					sum*=2;
				}
				ans+=sum;
			}
		}
	}
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn<<'\n';
		return 0;
	}else if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				maxn=(maxn,f(a[i],a[j]));
			}
		}
		cout<<maxn<<'\n';
	}else if(m==n){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=f(maxn,a[i]);
		}
		cout<<maxn<<'\n';
	}
	return 0;
}
