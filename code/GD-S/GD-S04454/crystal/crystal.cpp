#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long mid=0;
//	for(long long i=1;i<=n;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<endl;
	mid=(n+1)/2;
	long long ans=mid;
//	cout<<"mid:"<<mid<<endl;
	for(long long i=1;i<=mid;i++){
		m=m-(a[mid]-a[i]);
		a[i]=a[mid];
	}
	if(m==0){
		for(long long i=mid+1;i<=n;i++){
			if(a[mid]==a[i]){
				ans++;
			}
		}
	}else{
		for(long long i=mid+1;i<=n;i++){
			if(a[mid]==a[i]){
				ans++;
				continue;
			}
			long long ansans=0;
			for(int j=i;j>=1;j--){
				if(m==0){
					break;
				}else if(m<0){
					ansans-=1;
					break;
				}else{
					m=m-(a[i]-a[j]);
					ansans++;
				}
			}
			ans=max(ans,ansans);
		}
	}
	cout<<ans;
	return 0;
}


