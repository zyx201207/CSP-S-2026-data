#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long num1=-1;
long long nums[100010];
int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
	}
	for(int i=1;i<=n;i++){
		long long u=0;
		long long k=0;
		for(int j=1;j<=n;j++){
			if(u>m) break;
			if(nums[j]<=nums[i]){
				u+=(nums[i]-nums[j]);
				k++;
			}
		}
		if(u<=m) num1=max(k,num1);
	}
	cout<<num1;
	return 0;
}
