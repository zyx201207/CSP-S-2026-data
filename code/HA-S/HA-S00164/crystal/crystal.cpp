#include<bits/stdc++.h>
using namespace std;
long long n,m,mc,a[500005],ans,j,f=1,cha;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cha=a[1]-a[0];
	for(int i=2;i<=n;i++)if(a[i]-a[i-1]!=cha)f=0;
	if(f){
		int num=0;
		for(int i=1;i<=n;i++){
			if((num*i)/2>m){
				cout<<i-1;
				return 0;
			}
			else num+=cha;
		}
		return 0;
	}
	for(long long i=n;i>=1;i--){
		mc=m;
		for(j=i-1;j>=1;j--){
			if((mc-a[i]+a[j])>=0)mc-=a[i]-a[j];
			else{
				ans=max(ans,i-j);
				break;	
			}
		}
		if((mc>=0)&&(j==0))ans=max(ans,i);
	}
	cout<<ans;
	return 0;
}
