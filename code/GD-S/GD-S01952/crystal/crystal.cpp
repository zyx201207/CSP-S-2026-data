#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5*1e5+10;
int n,m,a[maxn],sum,maxx;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n);
	if(n>=500000){
		int ch=a[2]-a[1];
		int num=0;
		while(m!=0){
			if(m<num*ch)    break;
			m-=num*ch;
			num++;
		}
		if(num>n)    num=n;
		cout<<num;
		return ;
	}
	for(int i=2;i<=n;i++){
		int sor=m;
		sum=1;
		for(int j=i-1;j>=1;j--){
			if(sor<a[i]-a[j])    break;
			sor-=(a[i]-a[j]);
			sum++;
		}
		maxx=max(maxx,sum);
	}
	cout<<maxx;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)    solve();
}
