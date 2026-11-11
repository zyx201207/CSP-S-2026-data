#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int dis[N],n,sum[N];
long long m;
/*
long long add(int i,int j){
	long long anss=0;
	int cnt=0;
	for(int k=i+1;k<=j;k++){
		cnt++;
		anss+=dis[k]*cnt;
	}
	return anss;
}
*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int maxx=-1,minn=INT_MAX;
	for(int i=1;i<n;i++){
		dis[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+dis[i];
		maxx=max(maxx,dis[i]);
		minn=min(minn,dis[i]);
	}
	if(minn == m){
		cout<<2;
		return 0;
	}
	int i=0,j=1;
	int ans=0;
	
	long long t=dis[1];
	while(j<n && i<j){
		if(t>m){
			i++;j++;
			t=t-(sum[j]-sum[i-1]);
			t+=(j-i)*dis[j];
			//if(tex != t){
				//cout<<i<<' '<<j<<' '<<tex<<' '<<t<<'\n';
			//}
			continue;
		}
		if(t<=m){
			ans=max((j-i+1),ans);
			j++;
			t=t+(j-i)*dis[j];
			//if(tex != t){
				//cout<<i<<' '<<j<<' '<<tex<<' '<<t<<'\n';
			//}
		}
	}
	cout<<ans;
	return 0;
}
