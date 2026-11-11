#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int cas[5];
//case 3;
int t[N],dp[N];

//
void solve1(){
	int ans=0;
	for(int i=1;i<n;++i){
		if(ans+i>m){
			cout<<i;
			return ;
		}
		ans+=i;
	}
	cout<<n;
	return ;
}
void solve2(){
	int ans=0,dt=a[2]-a[1];
	for(int i=1;i<n;++i){
		if(ans+i*dt>m){
			cout<<i;
			return ;
		}
		ans+=i*dt;
	}
	cout<<n;
	return ;
}
//
int check(int x){
	//cout<<"case "<<x<<":";
	for(int i=1;i<=x;++i){
		t[i]=a[x]-a[i];
		//cout<<t[i]<<" ";
	}
	int cnt=0;
	for(int i=x-1;i>0;--i){
		if(cnt+t[i]>m){
			//cout<<n-i+1;
			return x-i;
		}
		cnt+=t[i]; 
	}
	return x;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]-a[i-1]!=1&&i!=1)cas[1]=1;
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])cas[2]=1;
	}
	//case A
	if(cas[1]==0){
		solve1();
		return 0;
	}
	//case B
	if(cas[2]==0){
		solve2();
		return 0;
	}
	//case 1~9
	int ctp=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		int w=check(i);//cout<<endl;
		ctp=max(ctp,w);
	}
	cout<<ctp;
	return 0;
}
