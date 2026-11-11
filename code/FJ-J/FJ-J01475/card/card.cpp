#include<bits/stdc++.h>
using namespace std;
int n,m,nums[5005],kards[3005],cntnum=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
		if(nums[i]!=nums[i-1]&&i!=1){
			kards[cntnum]=i-1;
			cntnum++;
		}
	}
	kards[cntnum]=n;
	for(int i=1;i<=m;i++){
		cout<<kards[i]<<" ";
	} 
	return 0;
} 
