#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int cnt;
	int m1=m;
	cnt=a[2]-a[1];
	int cnt1=1;
	while(m>=cnt){
		m-=cnt;
		cnt+=a[2]-a[1];
		cnt1++;
	}
	cout<<cnt1;
	return 0;
}
