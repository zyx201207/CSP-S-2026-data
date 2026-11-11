#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long maxx=0,minn=INT_MAX;
	for(int i=1;i<=n;i++){
		if(a[i]>maxx)maxx=a[i];
		if(a[i]<minn)minn=a[i];
	}
	long long zh=(minn+maxx)/2;
	long long maxn=INT_MAX;
	long long centre;
	for(int i=1;i<=n;i++){
		if(abs(a[i]-zh)<maxn){
			centre=a[i];
			maxn=abs(a[i]-zh);
		}
	}
	long long s[n+10];
	for(int i=1;i<=n;i++){
		s[i]=abs(a[i]-centre);
	}
	sort(s+1,s+n+1);
	int cnt=0;
	while(m>0){
		m-=s[cnt+1];
		cnt++;
		if(cnt>=n){
			break;
		}
	}
	cout<<cnt;
	return 0;
} 
