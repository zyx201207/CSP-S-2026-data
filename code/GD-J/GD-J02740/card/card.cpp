#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[500005];
int ans1[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int x=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt[m+5]={0};
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
			if(a[j]>1){
				ans[i]--;
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans[i]+=ans[i-1];
	}
	for(int i=1;i<=n;i++){
		ans[i]+=i;
	}
	for(int i=1;i<=n;i++){
		ans1[a[i]]+=ans[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans1[i]<<endl;
	}
	return 0;
} 
