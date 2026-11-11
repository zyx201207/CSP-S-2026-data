#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+5;
ll n,m;
ll a[N];
int ans=0;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll maxx=0,minn=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]);
	}
	//cout<<minn<<" "<<maxx<<endl;
	for(int i=minn;i<=maxx;i++) {
		int sum=0;
		ll b[N]={m+1};
		int fl=0;
		for(int j=1;j<=n;j++) {
			if(a[j]>i) continue;
			if(a[j]==i) {
				fl++;
				b[fl]=0;
			    continue;
			}
			fl++;
            b[fl]=i-a[j];
            //cout<<endl;
            //cout<<fl<<endl;
		}
		sort(b+1,b+fl+1);
		int cnt=0;
		for(int k=1;k<=fl;k++) {
		    cnt+=b[k];
		    if(cnt<=m) {
				sum++;
			}
			else break;
			//cout<<b[k]<<" ";
		}
		//cout<<'w'<<sum<<" ";
		ans=max(ans,sum);
	}
	//cout<<endl;
	cout<<ans<<endl;
	return 0;
}

/*
5 5
1 2 4 8 9
* 
5 8
-3 -1 2 2 7
* 
Oct31==Dec25?
* 
10 10
10 1 4 6 3 2 2 3 2 5
*/
