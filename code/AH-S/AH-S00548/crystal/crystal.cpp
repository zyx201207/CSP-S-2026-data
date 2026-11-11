#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum,mx=-0x3f3f3f3f3f3f3f3f,cnt,mm;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>=100000){
		int f=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) f=1;
		}
		if(f==0){
			long long ac=abs(a[2]-a[1]),t=0;
			while(sum+t*ac<=m&&t<=n){
				sum+=t*ac;
				t++;
				cnt++;
			}
			cout<<cnt;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cnt=1,mm=m;
		for(int j=i-1;j>=1;j--){
			if((a[i]-a[j])<=mm){
				mm-=(a[i]-a[j]);
				cnt++;
			}
			else{
				break;
			}
		}
		mx=max(mx,cnt);
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
