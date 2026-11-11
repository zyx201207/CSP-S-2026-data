#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans=1;
int cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long ma=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]!=ma&&m>0){
			long long x=ma-a[i];
			if(m>=x){
				m-=x;
				ans++;
			}else{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
