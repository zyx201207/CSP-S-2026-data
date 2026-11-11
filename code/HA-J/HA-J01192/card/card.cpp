#include<bits/stdc++.h>
using namespace std;
int arr[500005],f[500005];
int main(){
	freopen("card.in","R",stdin);
	freopen("card.out","W",stdout);
	int n,m,sum=0,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(sum==arr[i]){
			sum=0;
		}
		sum+=arr[i];
		f[i]++;
	}
	for(int i=1;i<=m;i++){
		cnt=0;
		if(arr[i]==i&&f[i]!=0){
			cnt++;
		}
		cout<<cnt<<" ";
	}
	return 0;
}
