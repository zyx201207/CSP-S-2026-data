#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	int ans=0;
	while(i<j){
		if(c[i]!=c[j]){
			ans+=min(a[i],a[j]);
		}	
		int t=min(a[i],a[j]);
		a[i]-=t;
		a[j]-=t;
//		cout<<i<<" "<<a[i]<<" "<<j<<" "<<a[j]<<endl; 
		if(a[i]==0)i++;
		if(a[j]==0)j--;
	}
	cout<<ans;
	return 0;
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3
6 a
7 b
9 c
*/
