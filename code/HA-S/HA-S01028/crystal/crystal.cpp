#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	if(n>=10000){
		bool f=0;
		long long biao;
		for(int i=1;i<=n;i++){
			if(a[i]*(i-1)-s[i-1]>m){
				f=1;
				biao=i;
				break;
			}
		}
		if(f==0){
			cout<<n;
			return 0;
		}
		biao--;
		int cnt=0;
		for(int i=biao+1;i<=n;i++){
			if(a[biao]==a[i]){
				cnt++;
			}
			else{
				break;
			}
		}
		biao+=cnt;
		cout<<biao;
		return 0;
	}
	int cnt=-1;
	for(int i=1;i<=n;i++){
		int las=0;
		for(int j=i+1;j<=n;j++){
			if(a[j]==a[i]){
				las++;
			}
			else{
				break;
			}
		}
		if(a[i]*(i-1)-s[i-1]>m){
			long long cha=m-a[i]*(i-1)+s[i-1];
			int j;
			for(j=1;j<=i;j++){
				cha+=(a[i]-a[j]);
				if(cha>0){
					break;
				}
			}
			cnt=max(i-j+las,cnt);
		}
		else{
			cnt=max(cnt,las+i);
		}
	}
	cout<<cnt;
	return 0;
}
