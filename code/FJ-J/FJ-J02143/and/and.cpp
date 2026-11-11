#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],maxx=-1e5,f[43]={0,0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,268435455,536870911,1073741823,2147483647,4294967295,8589934591,17179869183,34359738367,68719476735,137438953471,274877906943,549755813887,1099511627775};
void dfs(long long x,long long y,long long z,long long sum){
	if(x==y){
		maxx=max(sum,maxx);
		return;
	}
	for(int i=z;i<=n;i++){
		dfs(x+1,y,i,sum&a[i]);
	}
}
bool check(){
	for(int i=1;i<=n;i++){
		bool flag;
		for(int j=1;j<=40;j++){
			if(f[j]==a[i]) flag=true;
		}
		if(!flag) return false;
	}
	return true;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==m){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}else if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(check()){
		sort(a+1,a+n+1,cmp);
		long long sum=a[1];
		for(int i=2;i<=m;i++){
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			long long sum=1;
			for(int j=1;j<=n;j++){
				if(i!=j){
					sum&=a[j];
				}
			}
			maxx=max(maxx,sum);
		}
		cout<<maxx;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			dfs(0,m-1,i,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	return 0;
}
