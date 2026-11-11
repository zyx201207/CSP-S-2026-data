#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+10;
int n,m,arr[N],sum[N],flag[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int flag1=1,flag2=1;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]>arr[i-1]) flag1=0;
		if(arr[i]>2) flag2=0;
	}
	if(flag1==1){
		for(int i=1;i<=n;i++){
			memset(flag,0,sizeof(flag));
			for(int j=i;j<=n;j++){
				if(j==i){
					flag[arr[j]]=1;
					continue;
				}
				if(flag[arr[j]]==1){
					memset(flag,0,sizeof(flag));
					flag[arr[j]]=1;
				}
				else flag[arr[j]]=1;
			}
			for(int i=1;i<=m;i++){
				if(flag[i]==1) sum[i]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<sum[i]<<" ";
		}
	}
	else if(flag2==1){
		bool sum1=0,sum2=0;
		if(arr[n-1]==1&&arr[n]==2) sum1=n-1,sum2=n;
		else if(arr[n-1]==2&&arr[n]==1) sum1=n,sum2=n-1;
		else if(arr[n-1]==1&&arr[n]==1) sum1=n,sum2=0;
		else if(arr[n-1]==2&&arr[n]==2) sum1=0,sum2=n;
		cout<<sum1<<" "<<sum2;
	}
	else{
		deque<int> q;
		for(int i=1;i<=n;i++){
			memset(flag,0,sizeof(flag));
			for(int j=i;j<=n;j++){
				if(j==i){
					q.push_back(arr[j]);
					flag[arr[j]]=1;
					continue;
				}
				if(flag[arr[j]]==1){
					while(q.back()!=arr[j]){
						flag[q.back()]=0;
						q.pop_back();
					}
					q.pop_back();
					q.push_back(arr[j]);
				}
				else{
					q.push_back(arr[j]);
					flag[arr[j]]=1;
				}
			}
			for(int i=1;i<=m;i++){
				if(flag[i]==1) sum[i]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<sum[i]<<" ";
		}
	}
	return 0;
}
