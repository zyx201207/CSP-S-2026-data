#include<bits/stdc++.h>
using namespace std;

long long n,m,mid,ans=1;
long long a[500050];
unordered_map<long long,long long> mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mp[a[i]]++;
	}
	//The plan A is the Gunmu.Because I'm Qu.
	if(m>5000){ // plan B£¡ 
		pair<long long,long long> maxx={0,0};
		for(auto i:mp){
			if(i.second>maxx.second){
				maxx.second=i.second;
				maxx.first=i.first;
			}
		}
		sort(a+1,a+n+1);
		mid=(n+1)/2;
		
		int i=mid-1,j=mid+1;
		while(i>0&&a[i]==a[mid]){
//			printf("same!i=%d\n",i);
			i--;
			ans++;
		}
		while(j<=n&&a[j]==a[mid]){
//			printf("same!j=%d\n",j);
			j++;
			ans++;
		}
		if(maxx.second>ans){ // plan B-b!
			ans=1;
			int temp;
			for(temp=1;temp<=n;temp++){
				if(a[temp]==maxx.first){
//					printf("a[temp]=%d,temp=%d\n",a[temp],temp);
					break;
				}
			}
			mid=temp;
			i=mid-1,j=mid+1;
			while(i>0&&a[i]==a[mid]){
//				printf("same!i=%d\n",i);
				i--;
				ans++;
			}
			while(j<=n&&a[j]==a[mid]){
//				printf("same!j=%d\n",j);
				j++;
				ans++;
			}
		}
		while(m){
			if(i>0){
				if((a[mid]-a[i])<=m){
					m-=(a[mid]-a[i]);
					ans++;
				}
				i--;
			}
			else break;
		}
		printf("%lld",ans);
		return 0;
	}
	
	
	
	
	
	// plan C!
	sort(a+1,a+n+1);
	for(int cry=n;cry>1;cry--){
		long long ans1=1;
		long long temp=m;
		int i=cry-1;
//		printf("cry=%d,i=%d\n",cry,i);
		while(temp&&i>0){
//			printf("temp=%d,i=%d ; ",temp,i);
//			printf("a[cry]=%d,a[i]=%d ;",a[cry],a[i]);
			if(a[cry]-a[i]<=temp){
				ans1++;
				temp-=a[cry]-a[i];
//				printf("ans1=%d,(next)temp=%d,(next)i=%d\n",ans1,temp,i);
			}
			i--;
//			printf("\n");
		}
		ans=max(ans,ans1);
//		printf("ans=%d\n\n",ans);
	}
	printf("%lld",ans);
	
	return 0;
}
