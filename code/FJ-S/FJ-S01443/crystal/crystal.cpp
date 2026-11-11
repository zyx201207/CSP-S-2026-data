#include<bits/stdc++.h>
using namespace std;
long long a[1000500];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,x,y,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mx=-999;
	int cnt;
	for(int i=n;i>=1;i--){
		cnt=0;
		y=m;
		for(int j=1;j<=i;j++){
			if(a[i]-a[j]<=y){
				y-=a[i]-a[j];
				cnt++;
			}
		}	
		mx=max(mx,cnt);
	}
	cout<<mx;
	return 0;
} 
