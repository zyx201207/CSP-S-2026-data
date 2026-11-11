#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[114514514],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int num=0,q=0,an=0;
		for(int j=i;j<=n;j++){
			q+=a[j];
			num++;
			an=(a[j]*num)-q;
			if(an>m){
				ans=max(num-1,ans);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
