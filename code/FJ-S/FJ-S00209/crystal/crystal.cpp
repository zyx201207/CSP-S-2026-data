#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N],n,m,maxn,f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) f=0;
	}
	if(n>5000){
		if(!f){
			sort(a+1,a+n+1);
			int sum=0;
			for(int i=n;i>=1;i--){
				if(m-(a[n]-a[i])>=0){
					m-=(a[n]-a[i]);
					sum++;
				}else break;
			}
			cout<<sum;
		}else{
			int sum=0;
			for(int i=n;i>=1;i--){
				if(m-(a[n]-a[i])>=0){
					m-=(a[n]-a[i]);
					sum++;
				}else break;
			}
			cout<<sum;
		}
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll sum=1,k=m;
		for(int j=i-1;j>=1;j--){
			if(k-(a[i]-a[j])>=0){
				k-=(a[i]-a[j]);
				sum++;
			}else break;
		}
		maxn=max(maxn,sum);
	}
	cout<<maxn;
	return 0;
}
//15:19(75分?) 
//冲浪20819米，计时28.20！
//还不让玩小恐龙T-T
//最后祝蒋介石生日快乐 
