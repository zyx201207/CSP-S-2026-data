#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
bool s2=1,s3=1;
void solve1(){
	a[0]=a[n+1]=1e18;
	int ans=1,m1=m;
	for(int i=1;i<=n;i++){
		m=m1;
		int an=1;
		for(int j=i-1;;){
			int t1=abs(a[i]-a[j]);
			if(t1<=m)m-=t1,an++,j--;
			else break;
		}
		ans=max(ans,an);
	}
	cout<<ans<<"\n";
}
void solve2(){
	int ans=1;
	int d=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(m>=i*d)m-=i*d,ans++;
	}
	cout<<ans<<"\n";
}
void solve3(){
	int tmp[205]={},ans=0,m1=m;
	for(int i=1;i<=n;i++)tmp[a[i]+101]++;
	for(int i=1;i<=201;i++){
		int an=tmp[i];
		m=m1;
		for(int j=1;j<=201;j++){
			int num=(i-j>=1?tmp[i-j]:0);
			if(m>=num*j)m-=num*j,an+=num;
			else{
				an+=m/j;break;
			}
		}
		ans=max(an,ans);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1])s2=0;
		if(a[i]>100||a[1]>100)s3=0;
	}
	if(s2)solve2();
	else if(s3)solve3();
	else solve1();
	return 0;
}
//90 pts 
