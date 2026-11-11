#include<bits/stdc++.h>
using namespace std;
struct num{
	int nu[35];
}nums[200005];
int l,r,mid,a[200005],m,n,f[1048580],ans[35],bj=1;
int main(){
	//CHECK IT FIRST
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		nums[i].nu[0]=1;
		cin>>a[i];
		int tmp=a[i],bs=1;
		while(tmp>0){
			nums[i].nu[bs]=tmp%2;
			tmp/=2;
			bs++;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=30;j++) cout<<nums[i].nu[j]<<" ";
//		cout<<endl;
//	}
	for(int i=30;i>=1;i--){
		int count=0;
		for(int j=1;j<=n;j++){
			if(nums[j].nu[i]==1 && nums[j].nu[0] == 1) count++;
		}
		if(count>=m && bj==1){ 
			for(int j=1;j<=n;j++){
				if(nums[j].nu[i]==0) nums[j].nu[0]=0;
			}
			ans[i]=1;
		}
	}
	int out=0,ws=1;
//	for(int i=1;i<=30;i++) cout<<ans[i];
	for(int i=1;i<=30;i++){
		out=out+ws*ans[i];
		ws*=2;
	}
	cout<<out;
	return 0;
}
