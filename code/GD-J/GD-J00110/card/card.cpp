#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,biggest;
	cin>>n>>biggest;
	vector<long long> arr(n),cnt(biggest+1,0);
	for(long long i=0;i<n;i++){
		cin>>arr[i];
	}
	for(long long i=1;i<=n;i++){
		vector<long long> counting(biggest+1,0);
		for(long long j=i-1;j<n;j++){
			if(counting[arr[j]]==0){
				counting[arr[j]]++;
			}else{
				bool flag=false;
				for(long long x=i-1;x<=j;x++){
					if(arr[x]==arr[j]){
						flag=true;
					}
					if(flag){
						counting[arr[x]]=0;
					}else{
						counting[arr[x]]=1;
					}
				}
				counting[arr[j]]=1;
			}
		}
		for(long long x=1;x<=biggest;x++){
			if(counting[x]==1){
				cnt[x]++;
			}
		}
	}
	for(long long i=1;i<=biggest;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
