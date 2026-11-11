#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001];
long long ans=0,tot,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	/*for(int i=2;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}*/
	int i=2;
	
	n--;
	while(n--){
		long long d=m;
		tot=0;
		for(int pos=i-1;pos>=1;pos--){
			 
			if(d>=a[i]-a[pos]){
				
				d=d-a[i]+a[pos];
				tot++;
				
			}
			else
				break;
				
		}
		ans=max(ans,tot);
		i++;
	}
	cout<<ans+1;
	return 0;
}
