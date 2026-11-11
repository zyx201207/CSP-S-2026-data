#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],ans,lt=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		m-=(i-lt)*(a[i]-a[i-1]);
		while(m<0){
			m+=a[i]-a[lt];
			lt++;
		}
		ans=max(ans,i-lt+1);		
	}
	cout<<ans;
	return 0;
}
