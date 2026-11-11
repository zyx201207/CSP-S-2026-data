//GZ-S00136 贺良煜 贵阳市白云区华师一学校
#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt=1,p=0;
	cin>>n>>m;
	long long a[n];
	for(long long i=1 ; i<=n ; i++) cin>>a[i];
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	bool poi=1;
	for(long long i=1 ; i<=n ; i++){
		if(a[i]!=a[i-1]){
			poi=0;
			break;
		}
	}
	if(poi){
		cout<<n;
		return 0;
	}
	for(long long i=n-1 ; i>=1 ; i--){
		if(m-abs(a[n]-a[i])>=0){
			m-=abs(a[n]-a[i]);
			cnt++;
		}else break;
	}
	cout<<cnt;
	
	return 0;
}
