#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],ans,x,y;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		y=m;
		for(int j=i;j>=1;j--){
			if(abs(a[j]-a[j-1])>y){ans=max(ans,x);break;}
			else x++,y-=abs(a[i]-a[j-1]);
		}
		ans=max(ans,x);
		x=0;
	}
	cout<<ans;
}
