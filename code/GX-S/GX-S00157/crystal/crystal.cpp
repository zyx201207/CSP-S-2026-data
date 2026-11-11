#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int n,a[110000],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int k=m,cnt=0;
		for(int j=i-1;j>=1;j--){
			if(k<a[i]-a[j]){
				break;
			}
			k=k-(a[i]-a[j]);
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
