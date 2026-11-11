#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
int ans=0;
long long num=0;
void ck(long long mid){
	long long op=m;
	int ui=0;
	for(int i=n;i>=1;i--){
		if(a[i]<=mid){
			if(mid-a[i]<=op){
				op-=mid-a[i];
				ui++;
			}
		}
	}
	ans=max(ui,ans);
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			num=max(a[i],num);
		}
		long long io=a[2]-a[1];
		int e=0;
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=io){
				e=1;
				break;
			}
		}
		if(e==0){
			long long nans=1;
			long long iu=io;
			while(m>0){
				nans++;
				m-=iu;
				iu*=2;
			}
			cout<<nans;
			return 0;
		}
		for(long long i=1;i<=num;i++){
			ck(i);
		}
		cout<<ans;
	return 0;
} 
