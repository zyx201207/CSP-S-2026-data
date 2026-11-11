#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5;
int arr[maxn],cnt[maxn],px[maxn];
int n,m;
int main(){
	freopen("crystal.in","a",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		cnt[i]=arr[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j= 1;j<=m;j++){
			if(arr[i]+j==arr[j])px[i]++;
		}
	}
	sort(px+1,px+n+1);
	cout<<px[n]+1;
	return 0;
}
