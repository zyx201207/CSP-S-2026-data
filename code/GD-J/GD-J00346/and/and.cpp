#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 2e5+10;
int n,m;
int nums[MAXN];
bool choose_a[MAXN];

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int biggest=0;
	for(int i=0;i<n;i++){
		cin>>nums[i]; 
		biggest = max(nums[i],biggest);
	}
	for(int i=0;i<m;i++){
		choose_a[i]=1;
	}
	if(m=1){
		cout<<biggest;
		return 0;
	}
	int ans=0;
	if(m=2){
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				ans = max(nums[i]&nums[j],ans);
			}
		}
	}
	cout<<ans;
	return 0;
}
