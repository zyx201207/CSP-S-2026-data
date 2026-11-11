#include<iostream>
#include<algorithm>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=-1;
	for(int i=2;i<=n;i++){
		int cnt=1;
		int j=i-1;
		int tmp=m;
		while(j>=1&&tmp){
			if(tmp>=a[i]-a[j]) tmp-=a[i]-a[j],cnt++,j--;
			else break;
		}
		if(tmp){
			int k=i+1;
			while(k<=n&&tmp){
				if(tmp>=(a[k]-a[i])*(k-1)) tmp-=(a[k]-a[i])*(k-1),cnt++,k++;
				else break;
			}
			i=k-1;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
