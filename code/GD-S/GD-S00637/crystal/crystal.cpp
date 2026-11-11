#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e5+10;
long long n,a[maxn],ma=-2147483647;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int flag=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>100000){
			flag=1;
		}
	}
	if(flag){
		int cnt=m,ans=0;
		for(int i=n;i>=1;i--){
			int j=n-i;
			if(cnt>=j)cnt-=j;
			else break;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		long long cnt=0,mov=m;
		for(long long j=i;j>=1;j--){
			if(a[i]-a[j]<=mov){
				mov-=a[i]-a[j];
				cnt++;
			}else{
				break;
			}
		}
		ma=max(ma,cnt);
	}
	cout<<ma;
}



