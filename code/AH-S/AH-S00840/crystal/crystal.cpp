#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5;
#define ll long long
ll n,m;
ll a[N];
ll cnt;
int sum=1;
int j;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	cin>>n>>m;
	if(n==1){
		int x;
		cin>>x;
		cout<<1;
		return 0;
	}if(n==2){
		int x,y;
		cin>>x>>y;
		if(m>=max(x,y)-min(x,y)){
			cout<<2;
			return 0;
		}
		else cout<<1;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		cnt=a[i]-a[i-1];
	}
	for(int i=1;i;i++){
		if(i%2)j++;
		if(m-j*cnt>=0){
			m-=j*cnt;
			sum++;
		}else break;
	}
	cout<<sum;
	return 0;
}
