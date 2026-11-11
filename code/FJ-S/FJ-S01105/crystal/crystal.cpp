#include<bits/stdc++.h>
using namespace std;
int n;
unordered_map<long,int>mp;
long long m,a[500005],mx,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=2;i<=n;i++){
			long long tm=m,cnt=0;
			ans=1;
			for(int j=i;j>=2;j--){
				cnt+=a[j]-a[j-1];
				if(cnt<=tm){
					tm-=cnt;ans++;
				}
				else{
					break;
				}
			}
			mx=max(mx,ans);
		}
		printf("%lld",mx);
	}
	else{
		bool flagA=true,flagB=((a[1]-a[2])==(a[2]-a[3]));
		for(int i=1;i<=n;i++){
			if(a[i]!=i)flagA=false;
			if(i>3&&(a[i]-a[i-1])!=(a[i-1]-a[i-2]))flagB=false;
		}
		if(flagA){
//			printf("1\n");
			ans=0;
			long long cnt=0,tm=m;
			for(int i=1;ans<n;i++){
				cnt+=1;
				if(cnt<=tm){
					ans++;
					tm-=cnt;
				}
				else{
					break;
				}
			}
			printf("%lld",ans);
		}
		else if(flagB){
//			printf("2\n");
			long long d=a[2]-a[1],cnt=0,tm=m;ans=0;
			for(int i=1;ans<n;i++){
				cnt+=d;
				if(cnt<=tm){
					ans++;
					tm-=cnt;
				}
				else{
					break;
				}
			}
			printf("%lld",ans);
		}
		else{
			for(auto i:mp){
				if(i.second>mx)mx=i.second;
			}
			printf("%lld",mx);
		}
	}
	return 0;
}
	
