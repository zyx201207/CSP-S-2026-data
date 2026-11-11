#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,ans=0,o=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>2){
			o=1;
		}
	}
	if(o==0){
		cout<<m/(a[2]-a[1])+1;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long x=0,y=i,cnt=0;
		while(x<=m&&ans<n-i+2&&cnt<n&&y<n){
			x=x+(a[y]-a[y-1])*(y-i);
			cnt++;
			y++;
	
	
		}
		if(a[y-1]!=a[y-2]){
			cnt--;
		}
		if(x==m){
			ans=max(ans,cnt);
		}else{
			ans=max(ans,cnt);
			
		}
	}
	cout<<ans;
	return 0;
}
