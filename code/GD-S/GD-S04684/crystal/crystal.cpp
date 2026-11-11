#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500010],b[500010],ans; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	
	for(int i=1;i<=n;i++){
		long long cnt=m;
		long long sum=0;
		for(int j=1;j<=n;j++){
			b[j]=a[i]-a[j];
		}
		sort(b+1,b+n+1);
		
		int j=1;
		while(cnt>0&&j<=n){
			if(b[j]<0){
				j++;
				continue;
			}
			if(b[j]<=cnt&&b[j]>=0){
				cnt-=b[j++];
				sum++;
			}
			else
				break;
		}
		
		ans=max(ans,sum);
	}
	
	cout<<ans;
	
	return 0;
}
