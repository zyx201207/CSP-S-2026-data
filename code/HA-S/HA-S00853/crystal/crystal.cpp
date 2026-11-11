#include<bits/stdc++.h>
using namespace std;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//struct cap{
		//int z;
		//int q;
	//}a[1000001];
	//bool cmp(int x,int y){
	//	return cap.x>cap.y;
	//}
	long long a[10000001];
	int main(){
		long long n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=m;j++){
				if(a[i]+a[j]==(a[1]+a[n])/2-1){
					ans+=1;
				}
			}
		}
		cout<<ans;
	return 0;
}
