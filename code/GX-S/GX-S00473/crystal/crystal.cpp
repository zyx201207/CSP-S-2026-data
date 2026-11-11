#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],ans=0;
bool bbb=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			bbb=0;
			break;
		}
	}
	if(bbb==1){
		n<=m?cout<<n<<endl:cout<<m<<endl;
		return 0;
	}
	for(int i=2;i<=n;i++) c[i-1]=a[i]-a[i-1];
	for(int i=1;i<n;i++){
		long long cnt=0,cnt1=0;
		for(int j=i;j>=1;j--){
			if(cnt+c[j]<=m){
				cnt+=c[j];
				cnt1++;
				ans=max(ans,cnt1);
			}
			else break;
		}
	}
	cout<<++ans<<endl;
	return 0;
}
