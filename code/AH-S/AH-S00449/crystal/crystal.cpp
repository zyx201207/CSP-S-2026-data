#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,cnt,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	stable_sort(a+1,a+n+1);
	l=1;
	cnt=0;
	ans=1;
	for(int i=2;i<=n;i++){
		cnt=cnt+(a[i]-a[i-1])*(i-l);
		//cout<<cnt<<' ';
		while(cnt>m){
			cnt-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
