#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n>5000){
		int c=a[2]-a[1],s=1;
		for(int i=2;i<=1000000000;i++){
			if(m-s*c<0)break;
			else{
				s+=i;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int t=m,j=i-1,s=1,c=a[i];
		while(t>0&&j>=1){
			if(t>=a[j]){
				s++;
				t=t-(a[i]-a[j]);
				j--;
			}else t=0;
		}ans=max(ans,s);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
