#include<bits/stdc++.h>
#define int long long
#define qaq return 0;
using namespace std;
int n,m,a[500000+10],ma;
bool cmp(int x,int y){
	return x>y;
}                                                 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		int ans=0,cnt=m;
		for(int j=i;j<=n;j++){
			if(cnt-a[i]+a[j]>=0){
				cnt=cnt-a[i]+a[j];
				ans++;
			}
			if(cnt-a[i]+a[j]<0)break;
		}
		ma=max(ans,ma);
	}
	cout<<ma;
	qaq;
} 
