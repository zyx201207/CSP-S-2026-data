#include <bits/stdc++.h>
using namespace std;
int const N=5*1e5+10;
long long n,m;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long maxn=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<i;j++){
			long long num=0,cnt=0;
			if(a[j]==a[i]){
				continue;
			}else if(a[j]>a[i]){
				cnt++;
				continue;
			}
			if(a[i]-a[j]+num==m){
				maxn=max(maxn,i-cnt);
			}else if(a[i]-a[j]+num>m){
				break;
			}else{
				num+=a[i]-a[j];
			}
			maxn=max(maxn,i-cnt+1);
		}
	}
	cout<<maxn;
	return 0;
}


