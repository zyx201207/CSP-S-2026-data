#include<bits/stdc++.h>
#define ll long long
#define pr pair<int,int>
#define _1 first
#define _2 second
using namespace std;
const int N=5e5+5;
int n;
ll m;
ll a[N];
ll cz[N];
ll hf=0;
int cd=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		cz[i]=a[i]-a[i-1];
	}
	int j=1;
	ll sm=0;
	for(int i=2;i<=n;i++){
		sm+=cz[i];
		hf+=(i-j)*cz[i];
		while(hf>m){
			hf-=sm;
			sm-=cz[j+1];
			j++;
		}
		cd=max(cd,(i-j+1));
	}
	cout<<cd;
	return 0;
}
/*
5 0
1 2 4 8 9

5 8
-3 -1 2 2 7
ok啊让我来想一下哈
把一段区间内的值改成一样的 
5
3

-101 -101 -99 -99 -98 
*/ 
