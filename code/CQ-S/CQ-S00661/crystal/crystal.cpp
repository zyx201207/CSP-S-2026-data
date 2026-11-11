#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int a[n+1],b[n+1]; 
	a[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	bool flag=true;
	b[0]=a[1];
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
		if(i>=3&&b[i]!=b[i-1]) flag=false;
	}
	if(flag){
		cout<<m/b[2]<<endl;
		return 0;
	}//10 9 1 3 5 7 9 11 13 15 17 19
	int maxn=-1;
	for(int i=n;i>=2;i--){
		int ans=0,num=0;
		for(int j=i;j>=2;j--){
			num+=b[j],ans+=num;
			if(ans<=m) maxn=max(maxn,i-j+2);
			else break;
		}
	}
	cout<<maxn<<endl;
	return 0;
}
//Trick||Treat!
//5 5 1 2 4 8 9         3
//5 8 -3 -1 2 2 7       4

