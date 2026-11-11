#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m;
long long a[500005];
long long ans;
long long maxx=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		long long num=m;
		ans=1;
		for(int j=i-1;j>=1;j--){
			if(num<=0){
				break;
			}
			if(a[i]!=a[j]){
				num=num-a[i]+a[j];
				if(num<0){
					break;
				}
				ans++;
			}
			else{
				ans++;
				continue;
			}
		}
		if(maxx<ans){
			maxx=ans;
		}
	}
	cout<<maxx;
	return 0;
}
