#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,a[N],t[N],num[N],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int l=1; 
	t[1]=0,num[1]=1;
	for(int i=2;i<=n;i++){
		int k=a[i]-a[i-1];
		t[i]=t[i-1]+k*num[i-1];
		if(t[i]<=m){
			num[i]=num[i-1]+1;
			ans=max(num[i],ans);
			continue;
		}
		int p=num[i-1];
		while(t[i]>m){
			t[i]-=(a[i]-a[l]);
			l+=1; p-=1;
		}
		num[i]=p+1;
		ans=max(num[i],ans);
	}
	//for(int i=1;i<=n;i++) cout << t[i] << " ";
	//cout << "\n";
	cout << ans << "\n";
	return 0;
} 
/*
5 8 
-3 -1 2 2 7
5 5
1 2 4 8 9
*/
