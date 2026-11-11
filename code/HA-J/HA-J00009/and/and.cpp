#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1,minn=1000000010,a,x;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		maxn=max(maxn,x);
		minn=min(minn,x);
	}
	while(maxn>0){
		a++;
		maxn/=2;
	}
	while(minn>0){
		a--;
		minn/=2;
	}
	cout<<a;
	return 0;
}
