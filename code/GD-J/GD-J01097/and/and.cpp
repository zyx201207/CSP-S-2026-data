#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n,m;
ll power[32],a[200005];
bool b[200005],c[32];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=0;i<=31;i++){
		power[i]=pow(2,i);
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int amax;
	sort(a+1,a+1+n,greater<int>());
	for(int i=31;i>=0;i--){
		if(a[i]>=power[i]){
			amax=i;
			break;
		}
	}
	for(int i=amax;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(b[j]==0&&a[j]/power[i]%2==1)cnt++;
		}
		if(cnt>=m){
			c[i]=1;
			for(int j=1;j<=n;j++){
				if(b[j]==0&&a[j]/power[i]%2==0)
				b[j]=1;
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=31;i++){
		ans+=c[i]*power[i];
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12
0000 0011
0000 1111
0000 1010
0000 1010

5 3
31 3 1 15 7
0001 1111
0000 0011
0000 0001
0000 1111
0000 0111
*/
