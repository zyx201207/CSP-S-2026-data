#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using pii = pair<int,int> ;
int n,m,a[500100],s[500100];
int c(int mid,int i){
	int sum=(mid+1)*a[mid+i]-(s[mid+i]-s[i-1]);//mid=3,i=1
	if(sum>m)return 0;
	else return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int mx=-INF;
	for(int i=1;i<=n;i++){
		int l=1,r=n-i+1;
		while(l<r){
			int mid=(l+r)/2;
			if(c(mid,i))l=mid+1;
			else r=mid;
		}
		mx=max(mx,l);
	}
	cout<<mx;
	return 0;
}
/*
5 0
1 2 2 2 2
1 3 5 7 9
sum=0;
for(int j=i;j<=mid+i;j++){
	sum+=a[mid+i]-a[j];
}
sum+=a[3+i]-a[i];		
sum+=a[3+i]-a[i+1];
sum+=a[3+i]-a[i+2];
sum+=a[3+i]-a[i+3]; 
a[3+i]*4-(a[i]+a[i+1]+a[i+2]+a[i+3])
*/
