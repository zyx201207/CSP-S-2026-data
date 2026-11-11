#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],x,y,ma=-1,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		x=m;
		y=0;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=x){
				x-=(a[i]-a[j]);
			}else{
				y=j;
				break;
			}
		}
		if(ma<i-y)ma=i-y;
	}
	cout<<ma;
	return 0;
} 
