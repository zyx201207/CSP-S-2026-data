#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long sum=0;
	long long n,m;
	long long maxn=-1e12-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long q=m;
	sort(a+1,a+1+n);
	if(n<=5000){
		for(int i=n;i>=1;i--){
			sum=1;m=q;
			for(int j=i-1;j>=1;j--){
				if(m>=a[i]-a[j]){
					m-=(a[i]-a[j]);
					sum++;
				}
				else{
					break;
				}
			}
			maxn=max(maxn,sum);
		}
		cout<<maxn;
	} 
	else{
		long long ans=1;
		long long qq=a[2]-a[1];
		long long w=qq;
		while(1){		
			if(m-w>=0){
				ans++;
				m-=w;
				w+=qq;
			}
			else{
				break;
			}
		}
		cout<<ans;
	}
	return 0;
} 
/*
5 10 
1 3 5 7 9
*/
