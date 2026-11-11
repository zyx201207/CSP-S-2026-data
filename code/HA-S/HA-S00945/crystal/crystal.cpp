#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll a[N],m,n,sum;
ll s[N];
ll s1[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll x=n;
	int cntmax=-1;
	while(x--){
		for(int i=1;i<=n;i++){
			s1[i]=s[i];
		}
		for(int i=n-x;i<=n;i++)
			s1[i]=s1[i-1]+abs(a[i]-a[n-x]);
		int cnt=0;
		for(int i=n-x;i<=n;i++){
			if(s1[i]<=m)cnt++;
			else if(a[i]==a[i-1]&&i!=1)cnt++;
			else break;
		}
		if(cnt>cntmax)cntmax=cnt;
	}
	cout<<cntmax<<endl;
	return 0;
}
