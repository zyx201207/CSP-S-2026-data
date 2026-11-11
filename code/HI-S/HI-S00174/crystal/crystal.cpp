#include<bits/stdc++.h>
using namespace std;
long long  n,m;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	int f=0;
	for(int i=1;i<=n;i++){
		cin >>a[i]; 
	}
	if(n>1){
		int g=a[2]-a[1];
		for (int i=2;i<=n;i++){
			if(a[i]-a[i-1]==g){
				f++;
			}
		}
	}
	if(f==n){
		int ans=1;
		long long cnt=0;
		while(m>0 && ans<=n){
			 cnt++;
			 m-=cnt;
			 if(m>0){
			 	ans++;
			 }
		} 
		cout <<ans;
		return 0;
	}
	sort(a,a+n+1);
	long long ans=0;
	for (int i=1;i<=n;i++){
		long long sum=0;
		long long cnt=1;
		for (int j=i-1;j>=1;j--){
			 if(sum+(a[i]-a[j])<=m){
			 	sum+=a[i]-a[j];
			 	cnt++;
			 }
			 else{
			 	break;
			 }
		}
		ans=max(cnt,ans);
	}
	cout <<ans;
	return 0; 
}
