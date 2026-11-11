#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m;
struct num{
	long long wb;
	int maw;
}a[N];
int AAA(long long a){
	if(a==0) return 0;
	int cnt=1;
	while(a!=1){
		a>>=1;
		cnt++;
	}
	return cnt;
}
bool cmp(num a,num b){
	return a.wb>b.wb;
}
int sum[40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].wb;
		a[i].maw=AAA(a[i].wb);
		sum[a[i].maw]++;
	}
	if(m==1){
		long long ans=-1;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i].wb);
		}
		cout<<ans;
		return 0;
	}else if(m==n){
		long long ans=a[1].wb;
		for(int i=2;i<=n;i++){
			ans&=a[i].wb;
		}
		cout<<ans;
		return 0;
	}
	else{
		sort(a+1,a+n+1,cmp);
		int s=0;
		for(int i=33;i>=0;i--){
			if(sum[i]<m){
				s+=sum[i];
			}else{
				cout<<a[s+m].wb;
				return 0;
			}
		}
		cout<<a[m].wb;
	}
	return 0;
}
