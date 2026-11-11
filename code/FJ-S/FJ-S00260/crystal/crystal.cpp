#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+5;
int n,m,ans=1;
int a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	//int mid=a[(n+1)/2],mi=(n+1)/2;
	for(int i=2;i<=n;i++){
		int l=1,mid,mm=m;
		//if(i==2)mid=a[i];
		//else mid=a[(i+1)/2];
		for(int j=i;j>=1;j--){
			if(m-(a[i]-a[j])>0){
				m-=(a[i]-a[j]);
				l++;
				a[j]=a[i];
			}
			else break;
		}
		ans=max(ans,l);
	}
	cout<<ans;
	return 0;
}


/*
rp++ rp++ rp++!!!
求求了，二级就行
rp+=INF
*/ 
