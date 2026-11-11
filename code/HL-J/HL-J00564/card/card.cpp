#include<bits/stdc++.h>
using namespace std;
long long cards[500005];
long long nums[300005]={0};
long long nums2[300005]={0};
long long nums3[300005]={0};
long long ansn[300005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cards[i];
	}
	for(int i=1;i<=m;i++){
		nums[i]=n;
	}
	for(int i=n;i>=1;i--){
		nums2[cards[i]]++;
		if(nums2[cards[i]]==1){
			ansn[cards[i]]+=i;
		}
		if(nums2[cards[i]]>1){
			nums2[cards[i]]=1;
			for(int j=i+1;j<nums3[cards[i]];j++){
				if(nums2[cards[j]]==1){
					nums2[cards[j]]--;
					ansn[cards[j]]-=i;
				}
			}
		}
		nums3[cards[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<ansn[i]<<" ";
	}
	return 0;
}
