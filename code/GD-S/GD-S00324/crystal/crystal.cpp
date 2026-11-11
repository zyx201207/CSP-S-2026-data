#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N];
long long d[N];
long long d2[N];
long long l,sum;
long long cnt,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
		d2[i]=d[i]+d2[i-1];
	}
	for(int i=1;i<n;i++){
		cnt+=d[i]*(i-l);
		sum+=d[i];
		if(cnt<=m){
			ans=max((long long)i+1-l,ans);
		}else{
			while(cnt>m&&l<i){
				cnt=cnt-(d2[i]-d2[++l])-d[l];
			}
			ans=max((long long)i+1-l,ans);
		}
	}
	cout<<ans;
	return 0;
} 
