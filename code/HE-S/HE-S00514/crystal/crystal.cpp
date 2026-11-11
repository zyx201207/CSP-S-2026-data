#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m;
const LL N=5e5+10;
LL a[N];
int main(){
	freopen("crystal.in","r",stdin);
	//freopen("1.txt","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	LL ans=1;
	//时间复杂度：O(nlogn+max a*n) 
	//估分:60 
	for(LL i=1;i<=a[n];i++){//i:要把尽可能多的水晶的法力变成i 
		LL sum=0,mm=m;
		for(LL j=n;j>=1;j--){
			if(a[j]>i){
				continue;
			}else{
				LL cha=(i-a[j]);
				if(cha<=mm){
					mm-=cha;
					sum++;
				}
			}
		}
		ans=max(ans,sum);
	} 
	cout<<ans;
	return 0;
} 
