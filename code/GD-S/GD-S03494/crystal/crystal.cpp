#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
ll n,m,a[maxn],l,r,cnt,sum,maxx=-1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		sum=0;
		cnt=1;
		l=i-1;
		r=i+1;
		while(sum<=m && (l>=0 || r<n)){
			if(r>=n || a[i]-a[l]<=a[r]-a[i] && l>=0){
				sum+=a[i]-a[l];
				l--;
			}
			else if(l<0 || a[i]-a[l]>a[r]-a[i] && r<n){
				sum+=a[r]-a[i];
				r++;
			}
			cnt++;
		}
		if(sum>m)cnt--;
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
} 
//Oct31==Dec25?


