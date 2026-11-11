#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long ans=1;
	long long mid=0;
	long long midx=0;//离中间值最近的 
	long long midl=0;
	long long midr=0; 
	int ans1=0,ans2=0,ans3=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++){ 
		if(n%2==1){
			mid+=a[(n+1)/2];
			midl+=a[(n+1)/2-1];
			midr+=a[(n+1)/2+1];
			if(midl==mid){
				mid=midl;
			}
		}else{
			mid+=a[n/2];
			midl+=a[n/2-1];
			midr+=a[n/2+1];
		} 
		  
		if(mid-midl>midr-mid){//往右边走 
			midx=midr;
		}else if(mid-midl<midr-mid){//往左边走 
			midx=midl;
		}else{
			ans+=2;
			m=m-(mid-midl)*2;
		}
		
		if(midx>mid){ 
			mid=mid+(midx-mid);
			m=m-(midx-mid);
			ans++;
			//ans1++;
			continue;
		}else if(midx<mid){
			midx=midx+(mid-midx);
			m=m-(mid-midx);
			ans++;
			//ans2++;
			continue;
		}else if(midx==mid){
			ans++;
			//ans3++;
			continue;
		}
		m--;
		
	}
	cout<<ans/2<<endl;
	//cout<<ans1<<endl<<ans2<<endl<<ans3<<endl;
	return 0;
}
