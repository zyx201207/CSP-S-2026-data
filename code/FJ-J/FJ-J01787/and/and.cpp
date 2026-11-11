#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
bool cmp(int s1,int s2){
	return s1>s2;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ma=INT_MIN,ma1=INT_MIN;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n-m+1;i++){
		int x=a[i];
		for(int j=i;j<=i+m-1;j++){
			x&=a[j];
		}
		ma=max(ma,x);
	}
	for(int i=1;i<=n-m;i++){
		int y=a[i];
		for(int j=i;j<=i+m;j+=2){
			y&=a[j];
		}
		ma1=max(ma1,y);
	}
	cout<<max(ma,ma1);
	return 0;
}
