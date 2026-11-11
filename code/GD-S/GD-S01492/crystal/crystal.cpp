#include<bits/stdc++.h>
using namespace std;
int n,nums[int(5e5+1)];
long long fr[int(5e5+1)],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&nums[i]);
//		if(i>1) fr=nums[i]-nums[i-1];
		
	}sort(nums+1,nums+n+1);
	int mid=(n+1)/2;
	for(int i=1;i<=n;i++){
		fr[i]=abs(nums[i]-nums[mid]);
	}
	sort(fr+1,fr+n+1);
	for(int i=1;i<=n;i++){
//		printf("T:%lld\n",fr[i]+=fr[i-1]);
		if((fr[i]+=fr[i-1])>m){
			printf("%d",i-1);
			return 0;
		}
	}
	return 0;
}
