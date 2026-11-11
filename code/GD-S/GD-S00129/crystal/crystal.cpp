#include<iostream>
#include<cstdio>
#include<algorithm>
//greater
//priority_queue

long long a[500010];
long long s[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    long long m;
    
    std::cin>>n>>m;
    for(int i=1;i<=n;++i){
    	std::cin>>a[i];
	}
	std::sort(a+1,a+n+1);
	
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;++i){
//		for(int j=i;j<=n;++j){
//			if(i==j){
//				ans=std::max(1,ans);
//				continue;
//			}
//			if(1LL*a[j]*(j-i)-(s[j-1]-s[i-1])<=m){
//				ans=std::max(ans,j-i+1);
//			}
//		}
        int l=i,r=n+1;
        while(l+1<r){
        	int mid=(l+r)/2;
        	
        	if(1LL*a[mid]*(mid-i)-(s[mid-1]-s[i-1])<=m){
        		l=mid;
			}else r=mid;
		}
		ans=std::max(ans,l-i+1);
	}
	
	std::cout<<ans<<'\n';
	
	return 0;
}
