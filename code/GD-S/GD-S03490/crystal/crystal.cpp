#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1001011],b[1001011];
long long ans,cnt,now;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long k=n;
	for(int q=1;q<=n;q++){
		for(int i=1;i<=k-1;i++){
			b[i]=0;			
		}
		for(int i=1;i<=k-1;i++){
			b[i]=a[k]-a[i];			
		}
		cnt=1,ans=0;
		for(int i=k;i>=1;i--){
			if(ans+b[i]<=m){
				ans+=b[i];
				cnt++;
			}
			if(cnt>now)now=cnt;
			k--;
		}
	}
		cout<<now;
	return 0;
}
