#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long a[N],b[N];
long long n,m;
bool check(){
	int d1=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=d1){
			return 0;
		}
	}
	return 1;
}
int mian(){
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
	}	
	sort(a+1,a+n+1);
	if(a[1]==a[n]){
		cout<<n;
		return 0;
	}
	if(check()){
		int y=a[2]-a[1];
		long long ans=0;
		while(m>=y){
			ans++;
			m-=y;
			y*=2;
		}
		cout<<ans+1;
		return 0;
	}
	long long ans=0;
	
	for(int i=1;i<=n;i++){
		long long cnt=0;
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]>cnt){
				break;
			}
			if(a[i]-a[j]<=cnt){
				cnt=cnt-a[i]+a[j];
				b[j]=a[i];
			}
		}
		for(int j=2;j<=n;j++){
			if(b[j]==b[j-1]){
				cnt++;
			}
		}
		ans=max(ans,cnt+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
 	return 0;
 }
