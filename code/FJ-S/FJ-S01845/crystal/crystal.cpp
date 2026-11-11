#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500005],mid,sum=1,mm,ans;
int main(){ 
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
    	scanf("%lld",&a[i]); 
	} 
	sort(a+1,a+n+1);
	for(int ii=1;ii<=n;ii++){
		mid=ii;
		if(a[mid]==a[mid-1]){
			continue;
		}
		mm=m;
		ans=0;
		for(int i=mid-1;i>=1;i--){
			if(mm>a[mid]-a[i]){
			   mm-=(a[mid]-a[i]);
			   ans++;	
		    }else if(mm==a[mid]-a[i]){
		    	ans++;
		    }else{	
		        break;
		    }
	    }
	    ans+=(upper_bound(a+1,a+n+1,a[mid])-mid-a);
	    if(ans>sum){
	    	sum=ans;
	    }
	}
	printf("%lld",sum);
    return 0;
}
