#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
int n,cur;
int f1=1,f2=1;
ll m,a[500010],ans=0,sum,s[500010],cnt;
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i) f1=0;
	}
	if(f1==1){
		sum=0;
		for(int i=0;i<n;i++){
			if(sum+i<=m){
				ans++;
				sum+=i;
			}
			else break;
		}
		printf("%lld",ans);
		return 0;
	}
	stable_sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1]){
			f2=0;
			break;
		}
	}
	if(f2==1){
		for(int i=0;i<n;i++){
			if(sum+i*(a[2]-a[1])<=m){
				ans++;
				sum+=i*(a[2]-a[1]);
			}
			else break;
		}
		printf("%lld",ans);
		return 0;
	}
	//printf("%lld %lld",a[1],a[n]);
	cur=n;
	int j=1;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		for(;j<=i;j++){
			if((i-j+1)*a[i]-sum<=m) break;
			else{
				sum-=a[j];
			}
		}
		ans=max(ans,(long long)i-j+1);
	}
	/*for(int i=n;i>=1;i--){
		if(a[i]==a[i+1]) continue;
		//while(a[cur]>i&&cur>1) cur--;
		sum=0;cnt=0;
		for(int j=i;j>=1;j--){
			if(sum+a[i]-a[j]<=m){
				sum+=a[i]-a[j];
				cnt++;
			}
			else break;
		}
		ans=max(ans,cnt);
		if(ans==i) break;
	}*/
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
