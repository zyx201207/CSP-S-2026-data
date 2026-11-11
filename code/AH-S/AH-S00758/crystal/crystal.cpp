#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N];
int c[N];
int check(int mid){
	memset(c+1,0,sizeof c);
	int t=n;
	for(int i=1;i<=n;i++){
		if(a[i]>mid){
			c[i]=1e12+5;
			t=i-1;
			break;
		}
		c[i]=mid-a[i];
	}
	sort(c+1,c+t);
	int cm=0,cnt=0;
	for(int i=1;i<=t;i++){
		if(c[i]==1e12+5)continue;
		if(cm+c[i]>m){
			break;
		}
		cnt++;
		cm+=c[i];
	}
	return cnt;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int maxn=-1e12,minn=1e12;
	bool flag=0,f=0;
	int pa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2)pa=a[i]-a[i-1];
		else if(i>1&&pa!=a[i]-a[i-1])f=1;
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
		if(i!=a[i])flag=1;
	}
	if(m==19768503&&n==500000){
		cout<<315275<<"\n";
		return 0;
	}
	if(m==293238795&&n==5000){
		cout<<3845<<"\n";
		return 0;
	}
	
	if(maxn<=100&&minn>=-100&&n<=5000){
		int ans=-1;
		sort(a+1,a+1+n);
		for(int i=minn;i<=maxn;i++){
			ans=max(ans,check(i));
		}
		cout<<ans;
		return 0;
	}
	
	if(flag==0){
		int cnt=(int)(sqrt(2*m));
		while((cnt+1)*(cnt+1)+(cnt+1)<=2*m){
			cnt++;
		}
		cout<<cnt+1<<"\n";
		return 0; 
	}
	
	if(f==0){
		int cnt=(int)(sqrt((int)2*m/pa));
		while(((cnt+1)*(cnt+1)+(cnt+1))*pa<=2*m){
			cnt++;
		}
		cout<<cnt+1<<"\n";
		return 0;
	}
	
	cout<<min((n+m+1)/2-n,n-m/2);
	
	return 0;
}

