#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int g[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ma=INT_MIN;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			g[j]=a[i]-a[j];
		}
		int cnt=0,s=0;
		for(int j=i;j>=1;j--){
			if((cnt+g[j])>m){
				break;
			}
			cnt+=g[j];
			s++;
		}
		ma=max(ma,s);
	}
	cout<<ma;
	return 0;
}
