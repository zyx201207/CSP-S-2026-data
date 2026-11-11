#include<bits/stdc++.h>
using namespace std;
long long m,m1,bid,b,ans=0,dc,dc1;
long long a[500005];
int n,cnt=0;
bool f=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				f=0;
			}
		}
	}
	sort(a+1,a+1+n);
	if(f==1){
		dc=a[2]-a[1];
		dc1=dc;
		m1=m;
		cnt=1;
		while(m1>=dc1&&cnt<=n){
			m1-=dc1;
			dc1+=dc;
			cnt++;
		}
		cout<<min(cnt,n);
		return 0;
	}
	for(int i=n;i>=1;i--){
		m1=m;
		cnt=1;
		for(int j=i-1;j>=1;j--){
			if(m1>=a[i]-a[j]){
				m1-=(a[i]-a[j]);
				cnt++;
			}else{
				break;
			}
		}
		if(cnt>ans){
			ans=cnt;
		}
	}
	cout<<ans;
	return 0;
}
