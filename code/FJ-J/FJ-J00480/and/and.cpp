#include<bits/stdc++.h>
using namespace std;
long long a[214514];
bool b[214514];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[i]=1;
	}
	long long ans=0;
	for(long long i=31;i>=0;i--){
		long long cnt=0;
		for(long long j=1;j<=n;j++){
			if(!b[j]){
				continue;
			}
			if(a[j]&(1<<i)){
				cnt++;
			}
		} 
		if(cnt>=m){
			ans+=(1<<i);
			for(long long j=1;j<=n;j++){
				if((a[j]&(1ll<<i))==0){
					b[j]=0;
				}
			}
		}
		
	}
	cout<<ans;
} 
/*
5 3
4 4 5 5 5

100
100
101
101
101
*/
