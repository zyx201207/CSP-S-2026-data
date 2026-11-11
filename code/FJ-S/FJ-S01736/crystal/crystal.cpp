#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans = 1;
ll a[500005];
ll m,mm;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	scanf("%d%lld",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	mm = m;
	int i;
	for(i = 2;i<=n;i++){
		ll tmp = (a[i]-a[i-1])*(i-1);
		if(mm>=tmp){
			ans++;
			mm -= tmp;
		}else{
			break;
		}
	}
	int p = 1;
	for(;i<=n;i++){
		ll tmp = (a[i]-a[i-1])*(i-p);
		while(mm<tmp){
			tmp -= a[i]-a[p++];
		}
		mm -= tmp;
		ans = max(ans,i-p+1);
	}
	
	
	/*
	for(int i = 1;i<=n;i++){
		mm = m;
		int cnt = 0;
		for(int j = i;j>=1;j--){
			ll tmp = a[i]-a[j];
			if(mm-tmp>=0){
				mm -= tmp;
				cnt++;
			}else{
				break;
			}
		}
		ans = max(ans,cnt);
	}
	
	*/
	
	
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
