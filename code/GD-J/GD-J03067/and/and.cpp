#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define endl '\n'
using namespace std;
const int N=2e5+5;
int n,m,k=0,a[N],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k=max(k,(int)log2(a[i]));
	}
	for(int i=pow(2,k);i>=1;i/=2){
		int cnt=0;
		for(int j=1;j<=n;j++)
			if((a[j]&(ans+i))==ans+i) cnt++;
		if(cnt>=m) ans+=i;
	}
	cout<<ans;
	return 0;
}
