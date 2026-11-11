#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],d[500005],max1,sum[500005];
bool f=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			f=0;
		}
	}

	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+d[i];		
	}	
	if(f==1){
		//cout<<1<<"       ";
		for(int i=n;i>=1;i--){
			if(m-(a[n]-a[i])>=0){
				max1++;
				m-=(a[n]-a[i]);
			}else{
				break;
			}
		}
		cout<<max1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int t=a[i],k=m,cnt=0;
		for(int j=i;j>=1;j--){
			if(a[i]-a[j]<=k){
				cnt++;
				k-=(a[i]-a[j]);
			}else{
				break;
			}
		}
		//cout<<i<<" "<<cnt<<"\n";
		max1=max(max1,cnt);
	}
	cout<<max1;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
5 10000
-1 8 19 20 9
*/
