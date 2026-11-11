#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int s[500005];
bool check(int x,int i){
	int b=i-x;
	int c=b*a[i]-(s[i-1]-s[x-1]);
//	cout<<x<<" "<<i<<" "<<c<<endl;
	return c<=m;
}
int maxx;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int lt=1,rt=i,ans=0;
		while(lt<=rt){
			int mid=(lt+rt)/2;
//			cout<<mid<<" "<<i<<" "<<check(mid,i)<<endl; 
			if(check(mid,i)){
				ans=mid;
				rt=mid-1;
			}else{
				lt=mid+1;
			}
		}
//		cout<<ans<<endl;
		maxx=max(i-ans+1,maxx);
	}
	cout<<maxx;
	return 0;
}
/*
5 5
1 2 4 8 9
100pts
*/
