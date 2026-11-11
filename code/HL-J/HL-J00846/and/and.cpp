//如果是为了王女的话……
//写个特性也不是不行……
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int maxx;
int a[N];
int ans;
int solve(int a,int b){
	bitset<30> bs1;
	bitset<30> bs2;
	bitset<30> bs3;
	bs1=a;
	bs2=b;
	int c=max(a,b);
	int cnt=0;
	while(c){
		c>>=1;
		bs3[cnt]=bs1[cnt]&&bs2[cnt];
		cnt++;
	}
	int ret=0;
	for(int i=cnt-1;i>=0;i--){
		int p=0;
		ret+=bs3[i]*pow(2,p);
		p++;
	}
	return ret;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		ans=solve(ans,a[i]);
	}
	if(m==1){
		cout<<maxx;
	}
	else{
		cout<<ans;
	}
	return 0;
}
