#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=2e6+6;
int c,t,n,d;
int x[N];

void naruto(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)	cin>>x[i];
	int temp=x[2]-x[1];
	int num=d/temp;
	if(num==0||num==1){
		cout<<0<<endl;
		return;
	}
	num=num*2-1;
	cout<<max((int)0,n-num)<<endl;
	return;
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)	cin>>x[i];
	
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--)	naruto();
		return 0;
	}
	while(t--)	solve();
	return 0;
}
