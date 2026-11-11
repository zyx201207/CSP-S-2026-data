#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m;
int arr[N];
int a[N];
int ans[N];
int ins[N];
int idx=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=idx;j++){
			arr[j]=0;
		}
		idx=0;
		for(int j=i;j<=n;j++){
			bool x=1;
			for(auto k:arr){
				if(k==a[j]){
				x=0;
				break;
			}
			}
			if(x){
				arr[++idx]=a[j];
			}
			else{
				while(1){
					if(arr[idx]==a[j]){
						arr[idx]=0;
						idx--;
						break;
					}
					arr[idx]=0;
					idx--;
				}
				arr[++idx]=a[j];
			}
		}
		for(int i=1;i<=idx;i++){
			ans[arr[idx]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
/*
4 2
3 15 12 12

*/
