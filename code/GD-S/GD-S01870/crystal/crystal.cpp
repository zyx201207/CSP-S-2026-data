#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,a; 
long long max1,min1,min2,max2,max3,min3,best;
int main(){
	freopen("crystal.in","w",stdin);
	freopen("crystal.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	cin>>a;
	max1=a,min1=a,best=0,ans=1;
	for(int i=1;i<n;i++){
		cin>>a;
		if(a<min1){
			if(best+max1-a<=m){
				best+=max1-a,ans++,min2=min1,min1=a,min3=0;
				continue;
			}
		}
		if(a>max1){
			if(ans*(a-max1)+best<=m){
				best+=ans*(a-max1),max2=max1,max1=a,ans++,max3=0;
				continue;
			}
		}
		if(a==max1&&i!=1){
			ans++,max3++;
			continue;
		} 
		if(a==min1&&i!=1){
			if(best+max1-a<=m){
				best+=max1-a,ans++,min3++;
				continue;
			} 
		} 
		if(a<max1&&a>min1){
			if(best+max1-a<=m){
				best+=max1-a,ans++;
				continue;
			}else{
				if(a>max2&&a<max1&&max3==0){
					best-=(max1-a)*ans,max1=a,max3=0;
					continue;
				}
				if(a<min2&&a>min1&&min3==0){
					best-=(a-min1),min1=a,min3=0;
					continue;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
