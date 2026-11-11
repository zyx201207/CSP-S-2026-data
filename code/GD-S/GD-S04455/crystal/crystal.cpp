#include<bits/stdc++.h>
using namespace std;
long long m,n,arr[10005],q,o,brr[1005][1005],max1,crr[1005],a,k;
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n-1;j++){
			if(arr[j]>arr[j+1]){
				q=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=q;
			}
		}
	}

	for(long long i=n;i>=2;i--){
		for(long long j=i-1;j>=1;j--){
			brr[i][j]=arr[i]-arr[j];
		}
	}
	for(long long i=1;i<=n;i++){
		crr[i]=1;
	}
	for(long long i=2;i<=n;i++){
		a=m;
		k=i-1;
		while(a>=0&&k>=1){
			if(a-brr[i][k]<0){
				break;
			}
			crr[i]++;
			a-=brr[i][k];
			k--;
		}
	}
	max1=1;
	for(long long i=2;i<=n;i++){
		if(max1<crr[i]){
			max1=crr[i];
		}
	}
	cout<<max1;
	return 0;
}
